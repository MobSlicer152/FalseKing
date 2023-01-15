/*++

Copyright (c) 2023 MobSlicer152

Module Name:

    entityid.hpp

Abstract:

    This module defines the entity class for entt.

--*/

#pragma once

#include "falseking.hpp"

namespace Fk::Game
{

    class Entity
    {
    public:

        using EntityType = UINT32;
        using entity_type = EntityType;

    private:

        EntityType entt; // Do not rename, entt requires an entity_id named entt

    public:

        constexpr Entity(EntityType value = Ecs::null) noexcept
            : entt(value) {}

        constexpr Entity(const Entity& other) noexcept
            : entt(other.entt) {}

        constexpr operator EntityType() const noexcept
        {
            return entt;
        }
    };

}
