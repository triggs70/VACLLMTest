# Change Log

## Day 1

### Summary of Changes

This day marks the inception of the project. The repository was initialized with a standard Unreal Engine C++ project structure. The main feature added was a C++ Blueprint Function Library, `MyGameplayLib`, containing a function to spawn actors with a specific tag. A test map and a simple cube Blueprint were also created to utilize this new functionality.

*   **`Source/VACLabLLMTest/Public/MyGameplayLib.h`**: Defined the new `UMyGameplayLib` Blueprint Function Library and its `SpawnTaggedActor` function.
*   **`Source/VACLabLLMTest/Private/MyGameplayLib.cpp`**: Implemented the `SpawnTaggedActor` function with error handling.
*   **`Content/BP_Cube.uasset`**: A new Blueprint asset representing a simple cube.
*   **`Content/Test.umap`**: A new map file to test the new functionality.
*   **`.ignore`**: Updated to exclude common Unreal Engine and git files from source control.
*   **`.vscode/`**: Updated to include the new C++ files for proper IDE integration.
*   **`GEMINI.md`**: Added a context file for the Gemini model.

### Detailed Changes

#### `Source/VACLabLLMTest/Public/MyGameplayLib.h`

*   **`UMyGameplayLib` class created**
    *   **Before → After**: A new class `UMyGameplayLib` was created, inheriting from `UBlueprintFunctionLibrary`. It contains a single static function `SpawnTaggedActor`, which is exposed to Blueprints.
    *   **Behavioral Impact**: This introduces a new globally accessible function in the Blueprint editor, allowing for the creation of actors with a specific tag directly from any Blueprint graph.
    *   **Risks/Regression Areas**: None. This is a foundational feature.

#### `Source/VACLabLLMTest/Private/MyGameplayLib.cpp`

*   **`SpawnTaggedActor` function implemented**
    *   **Before → After**: The implementation for `SpawnTaggedActor` was added. It handles getting the world from a context object, spawning the actor, and adding the specified tag. It includes logging for error conditions.
    *   **Behavioral Impact**: Provides the core logic for the new Blueprint node. It will either successfully spawn a tagged actor or log a warning if it fails, preventing crashes from invalid inputs.
    *   **Risks/Regression Areas**: None. This is a new implementation.

#### `Content/BP_Cube.uasset` & `Content/Test.umap`

*   **New assets created**
    *   **Before → After**: These are new binary assets. `BP_Cube.uasset` is a simple actor Blueprint, and `Test.umap` is a level.
    *   **Behavioral Impact**: These assets provide a tangible way to test and demonstrate the new `SpawnTaggedActor` functionality within the Unreal Engine editor. The `Test` map likely uses the Level Blueprint to call `SpawnTaggedActor` to create an instance of `BP_Cube`.
    *   **Risks/Regression Areas**: None. These are new assets.

---

## Day 2

### Summary of Changes

*   **`Source/VACLabLLMTest/Private/RotateOverTimeComponent.cpp`**: Implemented the logic for the `URotateOverTimeComponent`, including the rotation itself and the pause functionality.
*   **`Source/VACLabLLMTest/Public/RotateOverTimeComponent.h`**: Defined the `URotateOverTimeComponent`, exposing the `bPaused` property to the editor.
*   **`Content/BP_Cube.uasset`**: Updated the `BP_Cube` Blueprint to include and use the new `URotateOverTimeComponent`.
*   **`Content/Test.umap`**: The test map was updated to reflect the changes in `BP_Cube`.

### Detailed Changes

#### `Source/VACLabLLMTest/Public/RotateOverTimeComponent.h`

*   **`bPaused` property added**
    *   **Before → After**: A new `UPROPERTY` `bPaused` of type `bool` was added to the `URotateOverTimeComponent` class.
    *   **Behavioral Impact**: This exposes a new checkbox in the Unreal Engine editor for actors with this component, allowing designers to control whether the rotation is active. It also allows developers to control the paused state from C++ or Blueprints.
    *   **Risks/Regression Areas**: None. This is a new feature and does not alter existing behavior.

#### `Source/VACLabLLMTest/Private/RotateOverTimeComponent.cpp`

*   **`TickComponent` function modified**
    *   **Before → After**: The `TickComponent` function now checks if `bPaused` is true at the beginning of the function. If it is, the function returns immediately.
    *   **Behavioral Impact**: The actor will not rotate when the `bPaused` property is true. This allows for dynamic pausing and resuming of the rotation.
    *   **Risks/Regression Areas**: None. This change is gated by the new `bPaused` property and preserves the original rotation behavior when `bPaused` is false.

---