/*********************                                                        */
/*! \file proof_rule.cpp
 ** \verbatim
 ** Top contributors (to current version):
 **   Andrew Reynolds
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2019 by the authors listed in the file AUTHORS
 ** in the top-level source directory) and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief Implementation of proof rule
 **/

#include "expr/proof_rule.h"

#include <iostream>

namespace CVC4 {

const char* toString(PfRule id)
{
  switch (id)
  {
    //================================================= Core rules
    case PfRule::ASSUME: return "ASSUME";
    case PfRule::SCOPE: return "SCOPE";

    //%%%%%%%%%%%%%  BEGIN SHOULD BE AUTO GENERATED
    case PfRule::SUBS: return "SUBS";
    case PfRule::REWRITE: return "REWRITE";
    case PfRule::SUBS_REWRITE: return "SUBS_REWRITE";
    //================================================= Boolean rules
    case PfRule::SPLIT: return "SPLIT";
    //================================================= Equality rules
    case PfRule::REFL: return "REFL";
    case PfRule::SYMM: return "SYMM";
    case PfRule::TRANS: return "TRANS";
    case PfRule::CONG: return "CONG";
    case PfRule::TRUE_INTRO: return "TRUE_INTRO";
    case PfRule::TRUE_ELIM: return "TRUE_ELIM";
    case PfRule::MACRO_EQ_SUBS_REWRITE: return "MACRO_EQ_SUBS_REWRITE";
    case PfRule::MACRO_REWRITE_PRED: return "MACRO_REWRITE_PRED";
    //================================================= String rules
    case PfRule::CONCAT_ENDP_UNIFY: return "CONCAT_ENDP_UNIFY";
    case PfRule::CONCAT_UNIFY: return "CONCAT_UNIFY";
    case PfRule::CONCAT_SPLIT: return "CONCAT_SPLIT";
    case PfRule::CONCAT_LPROP: return "CONCAT_LPROP";
    case PfRule::CONCAT_CPROP: return "CONCAT_CPROP";
    case PfRule::CTN_NOT_EQUAL: return "CTN_NOT_EQUAL";
    case PfRule::REDUCTION: return "REDUCTION";
    case PfRule::RE_INTER: return "RE_INTER";
    case PfRule::RE_UNFOLD: return "RE_UNFOLD";

    case PfRule::SIU_I_NORM_S: return "SIU_I_NORM_S";
    case PfRule::SIU_I_CONST_MERGE: return "SIU_I_CONST_MERGE";
    case PfRule::SIU_I_CONST_CONFLICT: return "SIU_I_CONST_CONFLICT";
    case PfRule::SIU_I_NORM: return "SIU_I_NORM";
    case PfRule::SIU_CARD_SP: return "SIU_CARD_SP";
    case PfRule::SIU_CARDINALITY: return "SIU_CARDINALITY";
    case PfRule::SIU_I_CYCLE_E: return "SIU_I_CYCLE_E";
    case PfRule::SIU_I_CYCLE: return "SIU_I_CYCLE";
    case PfRule::SIU_F_CONST: return "SIU_F_CONST";
    case PfRule::SIU_F_UNIFY: return "SIU_F_UNIFY";
    case PfRule::SIU_F_ENDPOINT_EMP: return "SIU_F_ENDPOINT_EMP";
    case PfRule::SIU_F_ENDPOINT_EQ: return "SIU_F_ENDPOINT_EQ";
    case PfRule::SIU_F_NCTN: return "SIU_F_NCTN";
    case PfRule::SIU_N_ENDPOINT_EMP: return "SIU_N_ENDPOINT_EMP";
    case PfRule::SIU_N_UNIFY: return "SIU_N_UNIFY";
    case PfRule::SIU_N_ENDPOINT_EQ: return "SIU_N_ENDPOINT_EQ";
    case PfRule::SIU_N_CONST: return "SIU_N_CONST";
    case PfRule::SIU_INFER_EMP: return "SIU_INFER_EMP";
    case PfRule::SIU_SSPLIT_CST_PROP: return "SIU_SSPLIT_CST_PROP";
    case PfRule::SIU_SSPLIT_VAR_PROP: return "SIU_SSPLIT_VAR_PROP";
    case PfRule::SIU_LEN_SPLIT: return "SIU_LEN_SPLIT";
    case PfRule::SIU_LEN_SPLIT_EMP: return "SIU_LEN_SPLIT_EMP";
    case PfRule::SIU_SSPLIT_CST: return "SIU_SSPLIT_CST";
    case PfRule::SIU_SSPLIT_VAR: return "SIU_SSPLIT_VAR";
    case PfRule::SIU_FLOOP: return "SIU_FLOOP";
    case PfRule::SIU_FLOOP_CONFLICT: return "SIU_FLOOP_CONFLICT";
    case PfRule::SIU_NORMAL_FORM: return "SIU_NORMAL_FORM";
    case PfRule::SIU_N_NCTN: return "SIU_N_NCTN";
    case PfRule::SIU_LEN_NORM: return "SIU_LEN_NORM";
    case PfRule::SIU_DEQ_DISL_EMP_SPLIT: return "SIU_DEQ_DISL_EMP_SPLIT";
    case PfRule::SIU_DEQ_DISL_FIRST_CHAR_EQ_SPLIT:
      return "SIU_DEQ_DISL_FIRST_CHAR_EQ_SPLIT";
    case PfRule::SIU_DEQ_DISL_FIRST_CHAR_STRING_SPLIT:
      return "SIU_DEQ_DISL_FIRST_CHAR_STRING_SPLIT";
    case PfRule::SIU_DEQ_DISL_STRINGS_SPLIT:
      return "SIU_DEQ_DISL_STRINGS_SPLIT";
    case PfRule::SIU_DEQ_STRINGS_EQ: return "SIU_DEQ_STRINGS_EQ";
    case PfRule::SIU_DEQ_LENS_EQ: return "SIU_DEQ_LENS_EQ";
    case PfRule::SIU_DEQ_NORM_EMP: return "SIU_DEQ_NORM_EMP";
    case PfRule::SIU_DEQ_LENGTH_SP: return "SIU_DEQ_LENGTH_SP";
    case PfRule::SIU_CODE_PROXY: return "SIU_CODE_PROXY";
    case PfRule::SIU_CODE_INJ: return "SIU_CODE_INJ";
    case PfRule::SIU_RE_NF_CONFLICT: return "SIU_RE_NF_CONFLICT";
    case PfRule::SIU_RE_UNFOLD_POS: return "SIU_RE_UNFOLD_POS";
    case PfRule::SIU_RE_UNFOLD_NEG: return "SIU_RE_UNFOLD_NEG";
    case PfRule::SIU_RE_INTER_INCLUDE: return "SIU_RE_INTER_INCLUDE";
    case PfRule::SIU_RE_INTER_CONF: return "SIU_RE_INTER_CONF";
    case PfRule::SIU_RE_INTER_INFER: return "SIU_RE_INTER_INFER";
    case PfRule::SIU_RE_DELTA: return "SIU_RE_DELTA";
    case PfRule::SIU_RE_DELTA_CONF: return "SIU_RE_DELTA_CONF";
    case PfRule::SIU_RE_DERIVE: return "SIU_RE_DERIVE";
    case PfRule::SIU_EXTF: return "SIU_EXTF";
    case PfRule::SIU_EXTF_N: return "SIU_EXTF_N";
    case PfRule::SIU_EXTF_D: return "SIU_EXTF_D";
    case PfRule::SIU_EXTF_D_N: return "SIU_EXTF_D_N";
    case PfRule::SIU_EXTF_EQ_REW: return "SIU_EXTF_EQ_REW";
    case PfRule::SIU_CTN_TRANS: return "SIU_CTN_TRANS";
    case PfRule::SIU_CTN_DECOMPOSE: return "SIU_CTN_DECOMPOSE";
    case PfRule::SIU_CTN_NEG_EQUAL: return "SIU_CTN_NEG_EQUAL";
    case PfRule::SIU_CTN_POS: return "SIU_CTN_POS";
    case PfRule::SIU_REDUCTION: return "SIU_REDUCTION";

    //%%%%%%%%%%%%%  END SHOULD BE AUTO GENERATED

    //================================================= Unknown rule
    case PfRule::UNKNOWN: return "UNKNOWN";
    default: return "?";
  }
}

std::ostream& operator<<(std::ostream& out, PfRule id)
{
  out << toString(id);
  return out;
}

}  // namespace CVC4
