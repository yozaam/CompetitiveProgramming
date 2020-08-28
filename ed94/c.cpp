

/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================
const int MOD = 1e7;
const int N = 2e6+13, M = N;
//=======================

int n, m;
//=======================



void solve() {

  string s  ; ll x;

  cin>>s>> x;

  //now if any 1 is a t distance of x... clear him!

  //if two ones have a dist of 2x then you can place in center of them ....
  //else ... place it in the first half or second half?

  int n =  s.size(),i;

  string w(n,'0');
  bool ok = true;
  fo(i,n){

    if(s[i] == '1')
    {
        ok = false;//don't know hwerer he came from

        if(i+x<n){

          if(i+x+x>=n ||
            s[i+x+x] =='1'){

            w[i+x] = '1';
            ok = 1;
          }
          
          //if he came from i+x;

          //i need to check i+x + x also!


        }

        if(i-x>=0){

          if(i-x-x<0 || 
            s[i-x-x] =='1'){

            w[i-x] = '1';
            ok = 1;

          }

          
        }

        // cout<<"\n i:"<<i<<"w:"<<w;
        if(!ok)break;//dont know where he came from..
    }
    
  }


  // cout<<"\n\nonce i did it became\n"<<s<<"\nthen reverse\n"<<ww;
  string ans = "-1";

  if(ok){
    ans = w;
  }

  cout<<ans<<"\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
      
    }

    return 0;
}



/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * vim: set ts=8 sts=2 et sw=2 tw=80:
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "frontend/ParseContext-inl.h"
#include "vm/EnvironmentObject-inl.h"

using mozilla::Maybe;
using mozilla::Nothing;
using mozilla::Some;

namespace js {
namespace frontend {

using AddDeclaredNamePtr = ParseContext::Scope::AddDeclaredNamePtr;
using DeclaredNamePtr = ParseContext::Scope::DeclaredNamePtr;

const char* DeclarationKindString(DeclarationKind kind) {
  switch (kind) {
    case DeclarationKind::PositionalFormalParameter:
    case DeclarationKind::FormalParameter:
      return "formal parameter";
    case DeclarationKind::CoverArrowParameter:
      return "cover arrow parameter";
    case DeclarationKind::Var:
      return "var";
    case DeclarationKind::Let:
      return "let";
    case DeclarationKind::Const:
      return "const";
    case DeclarationKind::Class:
      return "class";
    case DeclarationKind::Import:
      return "import";
    case DeclarationKind::BodyLevelFunction:
    case DeclarationKind::ModuleBodyLevelFunction:
    case DeclarationKind::LexicalFunction:
    case DeclarationKind::SloppyLexicalFunction:
      return "function";
    case DeclarationKind::VarForAnnexBLexicalFunction:
      return "annex b var";
    case DeclarationKind::SimpleCatchParameter:
    case DeclarationKind::CatchParameter:
      return "catch parameter";
    case DeclarationKind::PrivateName:
      return "private name";
  }

  MOZ_CRASH("Bad DeclarationKind");
}

bool DeclarationKindIsVar(DeclarationKind kind) {
  return kind == DeclarationKind::Var ||
         kind == DeclarationKind::BodyLevelFunction ||
         kind == DeclarationKind::VarForAnnexBLexicalFunction;
}

bool DeclarationKindIsParameter(DeclarationKind kind) {
  return kind == DeclarationKind::PositionalFormalParameter ||
         kind == DeclarationKind::FormalParameter;
}

bool UsedNameTracker::noteUse(JSContext* cx, const ParserAtom* name,
                              NameVisibility visibility, uint32_t scriptId,
                              uint32_t scopeId,
                              mozilla::Maybe<TokenPos> tokenPosition) {
  if (UsedNameMap::AddPtr p = map_.lookupForAdd(name)) {
    if (!p->value().noteUsedInScope(scriptId, scopeId)) {
      return false;
    }
  } else {
    // We need a token position precisely where we have private visibility.
    MOZ_ASSERT(tokenPosition.isSome() ==
               (visibility == NameVisibility::Private));

    if(visibility == NameVisibility::Private){
      // We have seen atleast one private name
      // how can I merge the equality check on line 76 and 78 ?
      hasPrivateNames_ = true;
    }
    

    UsedNameInfo info(cx, visibility, tokenPosition);

    if (!info.noteUsedInScope(scriptId, scopeId)) {
      return false;
    }
    if (!map_.add(p, name, std::move(info))) {
      return false;
    }
  }

  return true;
}

bool UsedNameTracker::getUnboundPrivateNames(
    Vector<UnboundPrivateName, 8>& unboundPrivateNames) {

  // We never saw any private names, so can just return early
  if(!hasPrivateNames_){
    return true;
  }

  for (auto iter = map_.iter(); !iter.done(); iter.next()) {
    // Don't care about public;
    if (iter.get().value().isPublic()) {
      continue;
    }

    // empty list means all bound
    if (iter.get().value().empty()) {
      continue;
    }

    if (!unboundPrivateNames.emplaceBack(iter.get().key(),
                                         *iter.get().value().pos())) {
      return false;
    }
  }

  // Return a sorted list in ascendng order of position.
  auto comparePosition = [](const auto& a, const auto& b) {
    return a.position < b.position;
  };
  std::sort(unboundPrivateNames.begin(), unboundPrivateNames.end(),
            comparePosition);

  return true;
}

bool UsedNameTracker::hasUnboundPrivateNames(
    JSContext* cx, mozilla::Maybe<UnboundPrivateName>& maybeUnboundName) {

  // We never saw any private names, so can just return early
  if(!hasPrivateNames_){
    return true;
  }

  Vector<UnboundPrivateName, 8> unboundPrivateNames(cx);
  if (!getUnboundPrivateNames(unboundPrivateNames)) {
    return false;
  }

  if (unboundPrivateNames.empty()) {
    return true;
  }

  // GetUnboundPrivateNames returns the list sorted.
  maybeUnboundName.emplace(unboundPrivateNames[0]);
  return true;
}

void UsedNameTracker::UsedNameInfo::resetToScope(uint32_t scriptId,
                                                 uint32_t scopeId) {
  while (!uses_.empty()) {
    Use& innermost = uses_.back();
    if (innermost.scopeId < scopeId) {
      break;
    }
    MOZ_ASSERT(innermost.scriptId >= scriptId);
    uses_.popBack();
  }
}

void UsedNameTracker::rewind(RewindToken token) {
  scriptCounter_ = token.scriptId;
  scopeCounter_ = token.scopeId;

  for (UsedNameMap::Range r = map_.all(); !r.empty(); r.popFront()) {
    r.front().value().resetToScope(token.scriptId, token.scopeId);
  }
}

void ParseContext::Scope::dump(ParseContext* pc) {
  JSContext* cx = pc->sc()->cx_;

  fprintf(stdout, "ParseScope %p", this);

  fprintf(stdout, "\n  decls:\n");
  for (DeclaredNameMap::Range r = declared_->all(); !r.empty(); r.popFront()) {
    UniqueChars bytes = QuoteString(cx, r.front().key());
    if (!bytes) {
      return;
    }
    DeclaredNameInfo& info = r.front().value().wrapped;
    fprintf(stdout, "    %s %s%s\n", DeclarationKindString(info.kind()),
            bytes.get(), info.closedOver() ? " (closed over)" : "");
  }

  fprintf(stdout, "\n");
}

bool ParseContext::Scope::addPossibleAnnexBFunctionBox(ParseContext* pc,
                                                       FunctionBox* funbox) {
  if (!possibleAnnexBFunctionBoxes_) {
    if (!possibleAnnexBFunctionBoxes_.acquire(pc->sc()->cx_)) {
      return false;
    }
  }

  return maybeReportOOM(pc, possibleAnnexBFunctionBoxes_->append(funbox));
}

bool ParseContext::Scope::propagateAndMarkAnnexBFunctionBoxes(
    ParseContext* pc) {
  // Strict mode doesn't have wack Annex B function semantics.
  if (pc->sc()->strict() || !possibleAnnexBFunctionBoxes_ ||
      possibleAnnexBFunctionBoxes_->empty()) {
    return true;
  }

  if (this == &pc->varScope()) {
    // Base case: actually declare the Annex B vars and mark applicable
    // function boxes as Annex B.
    Maybe<DeclarationKind> redeclaredKind;
    uint32_t unused;
    for (FunctionBox* funbox : *possibleAnnexBFunctionBoxes_) {
      if (pc->annexBAppliesToLexicalFunctionInInnermostScope(funbox)) {
        const ParserName* name = funbox->explicitName()->asName();
        if (!pc->tryDeclareVar(
                name, DeclarationKind::VarForAnnexBLexicalFunction,
                DeclaredNameInfo::npos, &redeclaredKind, &unused)) {
          return false;
        }

        MOZ_ASSERT(!redeclaredKind);
        funbox->isAnnexB = true;
      }
    }
  } else {
    // Inner scope case: propagate still applicable function boxes to the
    // enclosing scope.
    for (FunctionBox* funbox : *possibleAnnexBFunctionBoxes_) {
      if (pc->annexBAppliesToLexicalFunctionInInnermostScope(funbox)) {
        if (!enclosing()->addPossibleAnnexBFunctionBox(pc, funbox)) {
          return false;
        }
      }
    }
  }

  return true;
}

static bool DeclarationKindIsCatchParameter(DeclarationKind kind) {
  return kind == DeclarationKind::SimpleCatchParameter ||
         kind == DeclarationKind::CatchParameter;
}

bool ParseContext::Scope::addCatchParameters(ParseContext* pc,
                                             Scope& catchParamScope) {
  if (pc->useAsmOrInsideUseAsm()) {
    return true;
  }

  for (DeclaredNameMap::Range r = catchParamScope.declared_->all(); !r.empty();
       r.popFront()) {
    DeclarationKind kind = r.front().value()->kind();
    uint32_t pos = r.front().value()->pos();
    MOZ_ASSERT(DeclarationKindIsCatchParameter(kind));
    const ParserAtom* name = r.front().key();
    AddDeclaredNamePtr p = lookupDeclaredNameForAdd(name);
    MOZ_ASSERT(!p);
    if (!addDeclaredName(pc, p, name, kind, pos)) {
      return false;
    }
  }

  return true;
}

void ParseContext::Scope::removeCatchParameters(ParseContext* pc,
                                                Scope& catchParamScope) {
  if (pc->useAsmOrInsideUseAsm()) {
    return;
  }

  for (DeclaredNameMap::Range r = catchParamScope.declared_->all(); !r.empty();
       r.popFront()) {
    DeclaredNamePtr p = declared_->lookup(r.front().key());
    MOZ_ASSERT(p);

    // This check is needed because the catch body could have declared
    // vars, which would have been added to catchParamScope.
    if (DeclarationKindIsCatchParameter(r.front().value()->kind())) {
      declared_->remove(p);
    }
  }
}

ParseContext::ParseContext(JSContext* cx, ParseContext*& parent,
                           SharedContext* sc, ErrorReporter& errorReporter,
                           CompilationInfo& compilationInfo,
                           Directives* newDirectives, bool isFull)
    : Nestable<ParseContext>(&parent),
      traceLog_(sc->cx_,
                isFull ? TraceLogger_ParsingFull : TraceLogger_ParsingSyntax,
                errorReporter),
      sc_(sc),
      errorReporter_(errorReporter),
      innermostStatement_(nullptr),
      innermostScope_(nullptr),
      varScope_(nullptr),
      positionalFormalParameterNames_(cx->frontendCollectionPool()),
      closedOverBindingsForLazy_(cx->frontendCollectionPool()),
      innerFunctionIndexesForLazy(cx),
      newDirectives(newDirectives),
      lastYieldOffset(NoYieldOffset),
      lastAwaitOffset(NoAwaitOffset),
      scriptId_(compilationInfo.usedNames.nextScriptId()),
      superScopeNeedsHomeObject_(false) {
  if (isFunctionBox()) {
    if (functionBox()->isNamedLambda()) {
      namedLambdaScope_.emplace(cx, parent, compilationInfo.usedNames);
    }
    functionScope_.emplace(cx, parent, compilationInfo.usedNames);
  }
}

bool ParseContext::init() {
  if (scriptId_ == UINT32_MAX) {
    errorReporter_.errorNoOffset(JSMSG_NEED_DIET, js_script_str);
    return false;
  }

  JSContext* cx = sc()->cx_;

  if (isFunctionBox()) {
    // Named lambdas always need a binding for their own name. If this
    // binding is closed over when we finish parsing the function in
    // finishFunctionScopes, the function box needs to be marked as
    // needing a dynamic DeclEnv object.
    if (functionBox()->isNamedLambda()) {
      if (!namedLambdaScope_->init(this)) {
        return false;
      }
      AddDeclaredNamePtr p = namedLambdaScope_->lookupDeclaredNameForAdd(
          functionBox()->explicitName());
      MOZ_ASSERT(!p);
      if (!namedLambdaScope_->addDeclaredName(
              this, p, functionBox()->explicitName(), DeclarationKind::Const,
              DeclaredNameInfo::npos)) {
        return false;
      }
    }

    if (!functionScope_->init(this)) {
      return false;
    }

    if (!positionalFormalParameterNames_.acquire(cx)) {
      return false;
    }
  }

  if (!closedOverBindingsForLazy_.acquire(cx)) {
    return false;
  }

  return true;
}

bool ParseContext::annexBAppliesToLexicalFunctionInInnermostScope(
    FunctionBox* funbox) {
  MOZ_ASSERT(!sc()->strict());

  const ParserName* name = funbox->explicitName()->asName();
  Maybe<DeclarationKind> redeclaredKind = isVarRedeclaredInInnermostScope(
      name, DeclarationKind::VarForAnnexBLexicalFunction);

  if (!redeclaredKind && isFunctionBox()) {
    Scope& funScope = functionScope();
    if (&funScope != &varScope()) {
      // Annex B.3.3.1 disallows redeclaring parameter names. In the
      // presence of parameter expressions, parameter names are on the
      // function scope, which encloses the var scope. This means the
      // isVarRedeclaredInInnermostScope call above would not catch this
      // case, so test it manually.
      if (DeclaredNamePtr p = funScope.lookupDeclaredName(name)) {
        DeclarationKind declaredKind = p->value()->kind();
        if (DeclarationKindIsParameter(declaredKind)) {
          redeclaredKind = Some(declaredKind);
        } else {
          MOZ_ASSERT(FunctionScope::isSpecialName(sc()->cx_, name));
        }
      }
    }
  }

  // If an early error would have occurred already, this function should not
  // exhibit Annex B.3.3 semantics.
  return !redeclaredKind;
}

Maybe<DeclarationKind> ParseContext::isVarRedeclaredInInnermostScope(
    const ParserName* name, DeclarationKind kind) {
  Maybe<DeclarationKind> redeclaredKind;
  uint32_t unused;
  MOZ_ALWAYS_TRUE(tryDeclareVarHelper<DryRunInnermostScopeOnly>(
      name, kind, DeclaredNameInfo::npos, &redeclaredKind, &unused));
  return redeclaredKind;
}

bool ParseContext::isVarRedeclaredInEval(const ParserName* name,
                                         DeclarationKind kind,
                                         Maybe<DeclarationKind>* out) {
  MOZ_ASSERT(out);
  MOZ_ASSERT(DeclarationKindIsVar(kind));
  MOZ_ASSERT(sc()->isEvalContext());

  // TODO-Stencil: After scope snapshotting, this can be done away with.
  auto mbNameAtom = name->toJSAtom(sc()->cx_);
  if (mbNameAtom.isErr()) {
    return false;
  }
  JSAtom* nameAtom = mbNameAtom.unwrap();

  // In the case of eval, we also need to check enclosing VM scopes to see
  // if the var declaration is allowed in the context.
  js::Scope* enclosingScope = sc()->compilationInfo().enclosingScope;
  js::Scope* varScope = EvalScope::nearestVarScopeForDirectEval(enclosingScope);
  MOZ_ASSERT(varScope);
  for (ScopeIter si(enclosingScope); si; si++) {
    for (js::BindingIter bi(si.scope()); bi; bi++) {
      if (bi.name() != nameAtom) {
        continue;
      }

      switch (bi.kind()) {
        case BindingKind::Let: {
          // Annex B.3.5 allows redeclaring simple (non-destructured)
          // catch parameters with var declarations.
          bool annexB35Allowance = si.kind() == ScopeKind::SimpleCatch;
          if (!annexB35Allowance) {
            *out = Some(ScopeKindIsCatch(si.kind())
                            ? DeclarationKind::CatchParameter
                            : DeclarationKind::Let);
            return true;
          }
          break;
        }

        case BindingKind::Const:
          *out = Some(DeclarationKind::Const);
          return true;

        case BindingKind::Import:
        case BindingKind::FormalParameter:
        case BindingKind::Var:
        case BindingKind::NamedLambdaCallee:
          break;
      }
    }

    if (si.scope() == varScope) {
      break;
    }
  }

  *out = Nothing();
  return true;
}

bool ParseContext::tryDeclareVar(const ParserName* name, DeclarationKind kind,
                                 uint32_t beginPos,
                                 Maybe<DeclarationKind>* redeclaredKind,
                                 uint32_t* prevPos) {
  return tryDeclareVarHelper<NotDryRun>(name, kind, beginPos, redeclaredKind,
                                        prevPos);
}

template <ParseContext::DryRunOption dryRunOption>
bool ParseContext::tryDeclareVarHelper(const ParserName* name,
                                       DeclarationKind kind, uint32_t beginPos,
                                       Maybe<DeclarationKind>* redeclaredKind,
                                       uint32_t* prevPos) {
  MOZ_ASSERT(DeclarationKindIsVar(kind));

  // It is an early error if a 'var' declaration appears inside a
  // scope contour that has a lexical declaration of the same name. For
  // example, the following are early errors:
  //
  //   { let x; var x; }
  //   { { var x; } let x; }
  //
  // And the following are not:
  //
  //   { var x; var x; }
  //   { { let x; } var x; }

  for (ParseContext::Scope* scope = innermostScope();
       scope != varScope().enclosing(); scope = scope->enclosing()) {
    if (AddDeclaredNamePtr p = scope->lookupDeclaredNameForAdd(name)) {
      DeclarationKind declaredKind = p->value()->kind();
      if (DeclarationKindIsVar(declaredKind)) {
        if (dryRunOption == NotDryRun) {
          RedeclareVar(p, kind);
        }
      } else if (!DeclarationKindIsParameter(declaredKind)) {
        // Annex B.3.5 allows redeclaring simple (non-destructured)
        // catch parameters with var declarations.
        bool annexB35Allowance =
            declaredKind == DeclarationKind::SimpleCatchParameter;

        // Annex B.3.3 allows redeclaring functions in the same block.
        bool annexB33Allowance =
            declaredKind == DeclarationKind::SloppyLexicalFunction &&
            kind == DeclarationKind::VarForAnnexBLexicalFunction &&
            scope == innermostScope();

        if (!annexB35Allowance && !annexB33Allowance) {
          *redeclaredKind = Some(declaredKind);
          *prevPos = p->value()->pos();
          return true;
        }
      } else if (kind == DeclarationKind::VarForAnnexBLexicalFunction) {
        MOZ_ASSERT(DeclarationKindIsParameter(declaredKind));

        // Annex B.3.3.1 disallows redeclaring parameter names.
        // We don't need to set *prevPos here since this case is not
        // an error.
        *redeclaredKind = Some(declaredKind);
        return true;
      }
    } else if (dryRunOption == NotDryRun) {
      if (!scope->addDeclaredName(this, p, name, kind, beginPos)) {
        return false;
      }
    }

    // DryRunOption is used for propagating Annex B functions: we don't
    // want to declare the synthesized Annex B vars until we exit the var
    // scope and know that no early errors would have occurred. In order
    // to avoid quadratic search, we only check for var redeclarations in
    // the innermost scope when doing a dry run.
    if (dryRunOption == DryRunInnermostScopeOnly) {
      break;
    }
  }

  if (!sc()->strict() && sc()->isEvalContext() &&
      (dryRunOption == NotDryRun || innermostScope() == &varScope())) {
    if (!isVarRedeclaredInEval(name, kind, redeclaredKind)) {
      return false;
    }
    // We don't have position information at runtime.
    *prevPos = DeclaredNameInfo::npos;
  }

  return true;
}

bool ParseContext::hasUsedName(const UsedNameTracker& usedNames,
                               const ParserName* name) {
  if (auto p = usedNames.lookup(name)) {
    return p->value().isUsedInScript(scriptId());
  }
  return false;
}

bool ParseContext::hasUsedFunctionSpecialName(const UsedNameTracker& usedNames,
                                              const ParserName* name) {
  MOZ_ASSERT(name == sc()->cx_->parserNames().arguments ||
             name == sc()->cx_->parserNames().dotThis);
  return hasUsedName(usedNames, name) ||
         functionBox()->bindingsAccessedDynamically();
}

bool ParseContext::declareFunctionThis(const UsedNameTracker& usedNames,
                                       bool canSkipLazyClosedOverBindings) {
  // The asm.js validator does all its own symbol-table management so, as an
  // optimization, avoid doing any work here.
  if (useAsmOrInsideUseAsm()) {
    return true;
  }

  // Derived class constructors emit JSOp::CheckReturn, which requires
  // '.this' to be bound.
  FunctionBox* funbox = functionBox();
  const ParserName* dotThis = sc()->cx_->parserNames().dotThis;

  bool declareThis;
  if (canSkipLazyClosedOverBindings) {
    declareThis = funbox->functionHasThisBinding();
  } else {
    declareThis = hasUsedFunctionSpecialName(usedNames, dotThis) ||
                  funbox->isClassConstructor();
  }

  if (declareThis) {
    ParseContext::Scope& funScope = functionScope();
    AddDeclaredNamePtr p = funScope.lookupDeclaredNameForAdd(dotThis);
    MOZ_ASSERT(!p);
    if (!funScope.addDeclaredName(this, p, dotThis, DeclarationKind::Var,
                                  DeclaredNameInfo::npos)) {
      return false;
    }
    funbox->setFunctionHasThisBinding();
  }

  return true;
}

bool ParseContext::declareFunctionArgumentsObject(
    const UsedNameTracker& usedNames, bool canSkipLazyClosedOverBindings) {
  FunctionBox* funbox = functionBox();
  ParseContext::Scope& funScope = functionScope();
  ParseContext::Scope& _varScope = varScope();

  bool usesArguments = false;
  bool hasExtraBodyVarScope = &funScope != &_varScope;

  // Time to implement the odd semantics of 'arguments'.
  const ParserName* argumentsName = sc()->cx_->parserNames().arguments;

  bool tryDeclareArguments;
  if (canSkipLazyClosedOverBindings) {
    tryDeclareArguments = funbox->shouldDeclareArguments();
  } else {
    tryDeclareArguments = hasUsedFunctionSpecialName(usedNames, argumentsName);
  }

  // ES 9.2.12 steps 19 and 20 say formal parameters, lexical bindings,
  // and body-level functions named 'arguments' shadow the arguments
  // object.
  //
  // So even if there wasn't a free use of 'arguments' but there is a var
  // binding of 'arguments', we still might need the arguments object.
  //
  // If we have an extra var scope due to parameter expressions and the body
  // declared 'var arguments', we still need to declare 'arguments' in the
  // function scope.
  DeclaredNamePtr p = _varScope.lookupDeclaredName(argumentsName);
  if (p && p->value()->kind() == DeclarationKind::Var) {
    if (hasExtraBodyVarScope) {
      tryDeclareArguments = true;
    } else {
      usesArguments = true;
    }
  }

  if (tryDeclareArguments) {
    AddDeclaredNamePtr p = funScope.lookupDeclaredNameForAdd(argumentsName);
    if (!p) {
      if (!funScope.addDeclaredName(this, p, argumentsName,
                                    DeclarationKind::Var,
                                    DeclaredNameInfo::npos)) {
        return false;
      }
      funbox->setShouldDeclareArguments();
      usesArguments = true;
    } else if (hasExtraBodyVarScope) {
      // Formal parameters shadow the arguments object.
      return true;
    }
  }

  if (usesArguments) {
    // There is an 'arguments' binding. Is the arguments object definitely
    // needed?
    //
    // Also see the flags' comments in ContextFlags.
    funbox->setArgumentsHasVarBinding();

    // Dynamic scope access destroys all hope of optimization.
    if (sc()->bindingsAccessedDynamically()) {
      funbox->setAlwaysNeedsArgsObj();
    }
  }

  return true;
}

bool ParseContext::declareDotGeneratorName() {
  // The special '.generator' binding must be on the function scope, as
  // generators expect to find it on the CallObject.
  ParseContext::Scope& funScope = functionScope();
  const ParserName* dotGenerator = sc()->cx_->parserNames().dotGenerator;
  AddDeclaredNamePtr p = funScope.lookupDeclaredNameForAdd(dotGenerator);
  if (!p &&
      !funScope.addDeclaredName(this, p, dotGenerator, DeclarationKind::Var,
                                DeclaredNameInfo::npos)) {
    return false;
  }
  return true;
}

}  // namespace frontend

}  // namespace js







/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * vim: set ts=8 sts=2 et sw=2 tw=80:
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef frontend_UsedNameTracker_h
#define frontend_UsedNameTracker_h

#include "mozilla/Attributes.h"

#include "frontend/Token.h"
#include "js/AllocPolicy.h"
#include "js/HashTable.h"
#include "js/Vector.h"

#include "vm/StringType.h"

namespace js {
namespace frontend {

// A data structure for tracking used names per parsing session in order to
// compute which bindings are closed over. Scripts and scopes are numbered
// monotonically in textual order and unresolved uses of a name are tracked by
// lists of identifier uses, which are a pair of (ScriptId,ScopeId).
//
// For an identifier `i` with a use (ScriptId,ScopeId) in the Used list,
// ScriptId tracks the most nested script that has a use of u, and ScopeId
// tracks the most nested scope that is still being parsed (as the lists will be
// filtered as we finish processing a particular scope).
//
// ScriptId is used to answer the question "is `i` used by a nested function?"
// ScopeId is used to answer the question "is `i` used in any scopes currently
//                                         being parsed?"
//
// The algorithm:
//
// Let Used be a map of names to lists.
// Let Declared(ScopeId) be a list of declarations for a scope numbered with
// ScopeId
//
// 1. Number all scopes in monotonic increasing order in textual order.
// 2. Number all scripts in monotonic increasing order in textual order.
// 3. When an identifier `i` is used in (ScriptId,ScopeId), append that use to
//    the list Used[i] (creating the list and table entry if necessary).
// 4. When an identifier `i` is declared in a scope numbered ScopeId, append `i`
//    to Declared(ScopeId).
// 5. When we finish parsing a scope numbered with ScopeId, in script numbered
//    ScriptId, for each declared name d in Declared(ScopeId):
//   a. If d is found in Used, mark d as closed over if there is a value
//      (UsedScriptId, UsedScopeId) in Used[d] such that UsedScriptId > ScriptId
//      and UsedScopeId > ScopeId.
//   b. Remove all values uses in Used[d] where UsedScopeId > ScopeId.
//
// Steps 1 and 2 are implemented by UsedNameTracker::next{Script,Scope}Id.
// Step 3 is implemented by UsedNameTracker::noteUsedInScope.
// Step 4 is implemented by ParseContext::Scope::addDeclaredName.
// Step 5 is implemented by UsedNameTracker::noteBoundInScope and
// Parser::propagateFreeNamesAndMarkClosedOverBindings
//
// The following is a worked example to show how the algorithm works on a
// relatively simple piece of code. (clang-format is disabled due to the width
// of the example).

// clang-format off
//
// // Script 1, Scope 1
// var x = 1;                              // Declared(1) = [x];
// function f() {// Script 2, Scope 2
//     if (x > 10) { //Scope 3             // Used[x] = [(2,2)];
//         var x = 12;                     // Declared(3) = [x];
//         function g() // Script 3
//         { // Scope 4
//             return x;                   // Used[x] = [(2,2), (3,4)]
//         }                               // Leaving Script 3, Scope 4: No declared variables.
//     }                                   // Leaving Script 2, Scope 3: Declared(3) = [x];
//                                         // - Used[x][1] = (2,2) is not > (2,3)
//                                         // - Used[x][2] = (3,4) is > (2,3), so mark x as closed over.
//                                         // - Update Used[x]: [] -- Makes sense, as at this point we have
//                                         //                         bound all the unbound x to a particlar
//                                         //                         declaration..
//
//     else { // Scope 5
//         var x = 14;                     // Declared(5) = [x]
//         function g() // Script 4
//         { // Scope 6
//             return y;                   // Used[y] = [(4,6)]
//         }                               // Leaving Script 4, Scope 6: No declarations.
//     }                                   // Leaving Script 2, Scope 5: Declared(5) = [x]
//                                         // - Used[x] = [], so don't mark x as closed over.
//     var y = 12;                         // Declared(2) = [y]
// }                                       // Leaving Script 2, Scope 2: Declared(2) = [y]
//                                         // - Used[y][1] = (4,6) is > (2,2), so mark y as closed over.
//                                         // - Update Used[y]: [].

// clang-format on

struct UnboundPrivateName {
  const ParserAtom* atom;
  TokenPos position;

  UnboundPrivateName(const ParserAtom* atom, TokenPos position)
      : atom(atom), position(position) {}
};

class UsedNameTracker {
 public:
  struct Use {
    uint32_t scriptId;
    uint32_t scopeId;
  };

  class UsedNameInfo {
    friend class UsedNameTracker;

    Vector<Use, 6> uses_;

    void resetToScope(uint32_t scriptId, uint32_t scopeId);

    NameVisibility visibility_ = NameVisibility::Public;

    // The first place this name was used. This is important to track
    // for private names, as we will use this location to issue
    // diagnostics for using a name that's not defined lexically.
    mozilla::Maybe<TokenPos> firstUsePos_;

   public:
    explicit UsedNameInfo(JSContext* cx, NameVisibility visibility,
                          mozilla::Maybe<TokenPos> position)
        : uses_(cx), visibility_(visibility), firstUsePos_(position) {}

    UsedNameInfo(UsedNameInfo&& other) = default;

    bool noteUsedInScope(uint32_t scriptId, uint32_t scopeId) {
      if (uses_.empty() || uses_.back().scopeId < scopeId) {
        return uses_.append(Use{scriptId, scopeId});
      }
      return true;
    }

    void noteBoundInScope(uint32_t scriptId, uint32_t scopeId,
                          bool* closedOver) {
      *closedOver = false;
      while (!uses_.empty()) {
        Use& innermost = uses_.back();
        if (innermost.scopeId < scopeId) {
          break;
        }
        if (innermost.scriptId > scriptId) {
          *closedOver = true;
        }
        uses_.popBack();
      }
    }

    bool isUsedInScript(uint32_t scriptId) const {
      return !uses_.empty() && uses_.back().scriptId >= scriptId;
    }

    // To allow disambiguating public and private symbols
    bool isPublic() { return visibility_ == NameVisibility::Public; }

    bool empty() { return uses_.empty(); }

    mozilla::Maybe<TokenPos> pos() { return firstUsePos_; }
  };

  using UsedNameMap = HashMap<const ParserAtom*, UsedNameInfo,
                              DefaultHasher<const ParserAtom*>>;

 private:
  // The map of names to chains of uses.
  UsedNameMap map_;

  // Monotonically increasing id for all nested scripts.
  uint32_t scriptCounter_;

  // Monotonically increasing id for all nested scopes.
  uint32_t scopeCounter_;

  // Set if a private name was encountered.
  // Used to short circuit some private field early error checks
  bool hasPrivateNames_;

 public:
  explicit UsedNameTracker(JSContext* cx)
      : map_(cx), scriptCounter_(0), scopeCounter_(0), hasPrivateNames_(false) {}

  uint32_t nextScriptId() {
    MOZ_ASSERT(scriptCounter_ != UINT32_MAX,
               "ParseContext::Scope::init should have prevented wraparound");
    return scriptCounter_++;
  }

  uint32_t nextScopeId() {
    MOZ_ASSERT(scopeCounter_ != UINT32_MAX);
    return scopeCounter_++;
  }

  UsedNameMap::Ptr lookup(const ParserAtom* name) const {
    return map_.lookup(name);
  }

  MOZ_MUST_USE bool noteUse(
      JSContext* cx, const ParserAtom* name, NameVisibility visibility,
      uint32_t scriptId, uint32_t scopeId,
      mozilla::Maybe<TokenPos> tokenPosition = mozilla::Nothing());

  // Fill maybeUnboundName with the first (source order) unbound name, or
  // Nothing() if there are no unbound names.
  MOZ_MUST_USE bool hasUnboundPrivateNames(
      JSContext* cx, mozilla::Maybe<UnboundPrivateName>& maybeUnboundName);

  // Return a list of unbound private names, sorted by increasing location in
  // the source.
  MOZ_MUST_USE bool getUnboundPrivateNames(
      Vector<UnboundPrivateName, 8>& unboundPrivateNames);

  struct RewindToken {
   private:
    friend class UsedNameTracker;
    uint32_t scriptId;
    uint32_t scopeId;
  };

  RewindToken getRewindToken() const {
    RewindToken token;
    token.scriptId = scriptCounter_;
    token.scopeId = scopeCounter_;
    return token;
  }

  // Resets state so that scriptId and scopeId are the innermost script and
  // scope, respectively. Used for rewinding state on syntax parse failure.
  void rewind(RewindToken token);
};

}  // namespace frontend
}  // namespace js

#endif
