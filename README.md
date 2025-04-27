# Corner Grocer Item-Tracking Program

## Project Overview
The Corner Grocer item-tracking program, developed in C++ for CS 210, analyzes grocery purchase records to help optimize produce section layouts. It reads items from `CS210_Project_Three_Input_File.txt`, calculates their frequencies, and provides a menu-driven interface with four options: search for an item’s frequency, list all frequencies, display a histogram, and exit. The program also creates a backup file, `frequency.dat`, for data persistence. This project solves the problem of understanding item purchase patterns to improve store layout efficiency.

## Reflection

### What did you do particularly well?
I effectively implemented the `GroceryTracker` class using a `std::map` for efficient item-frequency storage, achieving O(log n) lookup performance. The code includes robust input validation, such as case-insensitive searches and numeric menu input checks, enhancing user experience. In-line comments and camelCase naming conventions improved readability, aligning with industry standards.

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could enhance the code by adding error handling for empty input files, which would prevent unexpected behavior. Implementing a file lock for `frequency.dat` would improve security in multi-user scenarios. Additionally, using a `std::unordered_map` could reduce lookup time to O(1) for large datasets, increasing efficiency. These changes would make the program more robust and scalable.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The case-insensitive search and input validation were challenging, as I needed to ensure consistent item name handling. I overcame this by using `std::transform` for lowercase conversion and `std::all_of` for alphabetic checks, referencing zyBooks sections 6.2 and 11.4. I’m adding the C++ Reference (cppreference.com) and Stack Overflow to my support network for future debugging and learning.

### What skills from this project will be particularly transferable to other projects or coursework?
Skills like class-based design, file I/O, and data structure selection (`std::map`) are transferable to projects requiring data processing or user interfaces. Input validation and error handling will aid in developing robust applications. My experience with Visual Studio and GitHub will support collaborative software development in future coursework.

### How did you make this program maintainable, readable, and adaptable?
The program is maintainable through modular functions (e.g., `loadInputFile`, `printHistogram`) and a clear class structure. In-line comments explain functionality, and consistent naming enhances readability. The `std::map` allows easy adaptation for new data types, and input validation ensures flexibility for varied user inputs, making the code adaptable to future requirements.

## Files
- `GroceryTracker.cpp`: C++ source code.
- `CS210_Project_Three_Input_File.txt`: Input file with grocery items.
- `CornerGrocer.sln`, `CornerGrocer.vcxproj`, `CornerGrocer.vcxproj.filters`: Visual Studio project files.
- `GroceryTracker_Documentation.docx`: Documentation with design description and screenshots.
