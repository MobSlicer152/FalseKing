/*++

Copyright (c) 2022 MobSlicer152

Module Name:

    main.cpp

Abstract:

    Creates the Game instance.

Author:

    MobSlicer152 23-Dec-2022

Revision History:

    23-Dec-2022    MobSlicer152

        Created main.cpp.

--*/

#include "falseking.hpp"

#include "game/game.hpp"

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
    Fk::GameInstance = new Fk::Game();
    Fk::GameInstance->Run();
    delete Fk::GameInstance;
}
