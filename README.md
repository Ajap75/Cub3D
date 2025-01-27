## Parsing Plan for Cub3D

### Objectives
- Parse the **map file** and validate its structure.
- Extract relevant configurations such as player position, map layout, and other parameters.

---

### Parsing Roadmap

1. **Initialize Map Parsing**:
   - Validate command-line input to ensure a `.cub` file is provided.
   - Open the map file and handle errors if the file is missing or inaccessible.

2. **Read and Clean File Content**:
   - Strip comments and empty lines.
   - Verify that all required sections (textures, colors, and map) are present and follow the correct order.

3. **Parse Configurations**:
   - **Textures**:
     - Validate paths for `NO`, `SO`, `WE`, `EA` identifiers.
     - Ensure paths point to existing files.
   - **Colors**:
     - Parse `F` (floor) and `C` (ceiling) colors.
     - Validate RGB values are integers in the range [0-255].

4. **Validate the Map**:
   - Check that the map uses only valid characters (`0`, `1`, `N`, `S`, `E`, `W`).
   - Confirm exactly one player start position is defined.
   - Ensure the map is surrounded by walls using the **floodfill algorithm** to check for leaks.

5. **Construct Data Structures**:
   - Create a 2D array to represent the map grid.
   - Store player start position and orientation separately for further use in rendering.

6. **Error Handling**:
   - Print `Error\n` followed by a detailed message for:
     - Invalid file format.
     - Missing or incorrect configurations.
     - Unclosed map boundaries.
     - Multiple or missing player start positions.
   - Exit the program gracefully after any error.

7. **Test and Iterate**:
   - Test with multiple `.cub` files to cover all edge cases:
     - Valid maps.
     - Maps with missing configurations.
     - Incorrectly formatted maps.
     - Maps with leaks or invalid characters.
   - Optimize error reporting to help identify issues quickly.

---

## Resources
- [Add useful links, code snippets, or diagrams here.]
