/*++

Copyright (c) 2023 MobSlicer152

Module Name:

    main.cpp

Abstract:

    Creates the Game instance.

--*/

#include "falseking.hpp"

#include "game/instance.hpp"

INT
main(
    IN PCHAR argv[],
    IN INT argc
    )
/*++

Routine Description:

    Creates the Game instance.

Arguments:

    argv - Arguments.

    argc - Number of arguments.

Return Value:

   0 - Success

   errno value - Failure

--*/
{
    Fk::Game::GlobalInstance = std::make_unique<Fk::Game::Instance>(
        "False King",
        1024,
        576
        );
    Fk::Game::GlobalInstance->Run();
    Fk::Game::GlobalInstance.release();
}
