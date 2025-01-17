// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Radu Serban
// =============================================================================
//
// Generic vehicle Pitman arm steering model.
//
// =============================================================================

#include "chrono_models/vehicle/generic/steering/Generic_PitmanArm.h"

namespace chrono {
namespace vehicle {
namespace generic {

// -----------------------------------------------------------------------------
// Static variables

const double Generic_PitmanArm::m_steeringLinkMass = 3.681;
const double Generic_PitmanArm::m_pitmanArmMass = 1.605;

const double Generic_PitmanArm::m_steeringLinkRadius = 0.03;
const double Generic_PitmanArm::m_pitmanArmRadius = 0.02;

const double Generic_PitmanArm::m_maxAngle = 30.0 * (CH_C_PI / 180);

const ChVector<> Generic_PitmanArm::m_steeringLinkInertiaMoments(0.252, 0.00233, 0.254);
const ChVector<> Generic_PitmanArm::m_steeringLinkInertiaProducts(0.0, 0.0, 0.0);
const ChVector<> Generic_PitmanArm::m_pitmanArmInertiaMoments(0.00638, 0.00756, 0.00150);
const ChVector<> Generic_PitmanArm::m_pitmanArmInertiaProducts(0.0, 0.0, 0.0);

// -----------------------------------------------------------------------------

Generic_PitmanArm::Generic_PitmanArm(const std::string& name) : ChPitmanArm(name) {}

const ChVector<> Generic_PitmanArm::getLocation(PointId which) {
    switch (which) {
        case STEERINGLINK:
            return ChVector<>(0.129, 0, 0);
        case PITMANARM:
            return ChVector<>(0.064, 0.249, 0);
        case REV:
            return ChVector<>(0, 0.249, 0);
        case UNIV:
            return ChVector<>(0.129, 0.249, 0);
        case REVSPH_R:
            return ChVector<>(0, -0.325, 0);
        case REVSPH_S:
            return ChVector<>(0.129, -0.325, 0);
        case TIEROD_PA:
            return ChVector<>(0.195, 0.448, 0.035);
        case TIEROD_IA:
            return ChVector<>(0.195, -0.448, 0.035);
        default:
            return ChVector<>(0, 0, 0);
    }
}

const ChVector<> Generic_PitmanArm::getDirection(DirectionId which) {
    switch (which) {
        case REV_AXIS:
            return ChVector<>(0, 0, 1);
        case UNIV_AXIS_ARM:
            return ChVector<>(0, 0, 1);
        case UNIV_AXIS_LINK:
            return ChVector<>(1, 0, 0);
        case REVSPH_AXIS:
            return ChVector<>(0, 0, 1);
        default:
            return ChVector<>(0, 0, 1);
    }
}

}  // namespace generic
}  // end namespace vehicle
}  // end namespace chrono
