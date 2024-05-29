//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LikelihoodFunctionBase.h"

InputParameters
LikelihoodFunctionBase::validParams()
{
  InputParameters params = MooseObject::validParams();
  params.addClassDescription("Base class for likelihood functions");
  params.registerBase("LikelihoodFunctionBase");
  params.registerSystemAttributeName("LikelihoodFunctionBase");
  return params;
}

LikelihoodFunctionBase::LikelihoodFunctionBase(const InputParameters & parameters)
  : MooseObject(parameters)
{
}
template <template <typename...> class R = std::vector,
          typename Top,
          typename Sub = typename Top::value_type>
R<typename Sub::value_type>
flatten(Top const & all)
{
  R<typename Sub::value_type> accum;
  for (auto & sub : all)
    std::copy(std::begin(sub), std::end(sub), std::inserter(accum, std::end(accum)));
  return accum;
}
Real
LikelihoodFunctionBase::function(const std::vector<std::vector<Real>> & x) const
{
  std::vector<Real> x2 = flatten(x);
  return function(x2);
}