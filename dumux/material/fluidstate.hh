// $Id$
/*****************************************************************************
 *   Copyright (C) 2009 by Andreas Lauser
 *   Institute of Hydraulic Engineering                                      *
 *   University of Stuttgart, Germany                                        *
 *   email: <givenname>.<name>@iws.uni-stuttgart.de                          *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version, as long as this copyright notice    *
 *   is included in its original form.                                       *
 *                                                                           *
 *   This program is distributed WITHOUT ANY WARRANTY.                       *
 *****************************************************************************/
/*!
 * \file
 *
 * \brief Abstract base class representing a fluid state
 *        (thermodynamic equilibrium properties and composition) of
 *        multi-component fluids.
 */
#ifndef DUMUX_FLUID_STATE_HH
#define DUMUX_FLUID_STATE_HH

#include <dumux/common/exceptions.hh>

namespace Dumux
{
/*!
 * \brief Abstract base class representing a fluid state
 *        (thermodynamic equilibrium properties and composition) of
 *        multi-component fluids.
 *
 * This class does _not_ provide an concrete API for calculating this
 * equilibrium from primary variables but merely defines how to access
 * the resulting quantities if the equilibrium has been computed.
 */
template <class Scalar, class Implementation>
class FluidState
{
public:
    FluidState()
    {
        if (0) {
            int i;
            // make sure the implementation specifies the required
            // enums
            i = Implementation::numPhases;
            i = Implementation::numComponents;
            i = Implementation::numSolvents;
        }
    }

    //! The maximum number of phases that can occur in the fluid
    //! system
    enum { numPhases };
    //! The number of the fluid system's chemical (pseudo-) species
    enum { numComponents };

    //! The number of "highly" miscible components in which only
    //! traces of the remaining components are resolved in the liquid
    //! phases.
    enum { numSolvents };

    /*!
     * \brief Return saturation of a phase
     */
    Scalar saturation(int phaseIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::saturation()"); }

    /*!
     * \brief Return the mole fraction of a component within a phase.
     */
    Scalar moleFrac(int phaseIdx, int compIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::moleFrac()"); }

    /*!
     * \brief Return the sum of the concentrations of all components
     *        for a phase.
     *
     * Unit: [mol/m^3]
     */
    Scalar phaseConcentration(int phaseIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::phaseConcentration()"); }

    /*!
     * \brief Return the concentrations of an individual component in
     *        a phase.
     *
     * Unit: [mol/m^3]
     */
    Scalar concentration(int phaseIdx, int compIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::concentration()"); }

    /*!
     * \brief Return the density of a phase.
     *
     * Unit: [kg/m^3]
     */
    Scalar density(int phaseIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::density()"); }

    /*!
     * \brief Return the average molar mass of a phase.
     *
     * This is the sum of all molar masses times their respective mole
     * fractions in the phase.
     *
     * Unit: [kg/m^3]
     */
    Scalar averageMolarMass(int phaseIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::averageMolarMass()"); }

    /*!
     * \brief Return the partial pressure of a component in the gas phase.
     *
     * For an ideal gas, this means R*T*c.
     *
     * Unit: [Pa] = [N/m^2]
     */
    Scalar fugacity(int componentIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::fugacity()"); }

    /*!
     * \brief Return the total pressure of the gas phase.
     *
     * Unit: [Pa] = [N/m^2]
     */
    Scalar phasePressure(int phaseIdx) const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::totalPressure()"); }

    /*!
     * \brief Return the temperature at which the equilibrium was
     *        calculated.
     *
     * Unit: [Pa] = [N/m^2]
     */
    Scalar temperature() const
    { DUNE_THROW(Dune::NotImplemented, "FluidState::temperature()"); }

protected:
    Implementation &asImp_()
    { return *((Implementation*) this); }
    const Implementation &asImp_() const
    { return *((const Implementation*) this); }
};

} // namespace Dumux

#endif