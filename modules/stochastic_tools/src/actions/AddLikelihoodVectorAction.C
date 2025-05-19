//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "AddLikelihoodVectorAction.h"
#include "Factory.h"
#include "FEProblem.h"
#include "LikelihoodFunctionVectorBase.h"

registerMooseAction("StochasticToolsApp", AddLikelihoodVectorAction, "add_likelihood");

InputParameters
AddLikelihoodVectorAction::validParams()
{
  InputParameters params = MooseObjectAction::validParams();
  params.addClassDescription("Adds LikelihoodVector objects.");
  return params;
}

AddLikelihoodVectorAction::AddLikelihoodVectorAction(const InputParameters & params) : MooseObjectAction(params)
{
}

void
AddLikelihoodVectorAction::act()
{
  _problem->addObject<LikelihoodFunctionVectorBase>(
      _type, _name, _moose_object_pars, /* threaded = */ false);
}
