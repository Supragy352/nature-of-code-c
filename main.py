import os

def print_directory_structure(start_path, output_file=None, indent=0, max_depth=None):
    """
    Recursively print the directory structure starting from start_path up to a specified depth.
    
    :param start_path: Path to start printing the directory structure.
    :param output_file: File object to write the output, if specified.
    :param indent: Current level of indentation for the structure.
    :param max_depth: Maximum depth to scan. None means no limit.
    """
    if max_depth is not None and indent >= max_depth:
        return

    try:
        # List all files and folders in the directory
        items = os.listdir(start_path)
        for item in items:
            item_path = os.path.join(start_path, item)
            # Add indentation and print item
            line = '  ' * indent + f'|- {item}\n'
            if output_file:
                output_file.write(line)
            else:
                print(line, end="")
            # Recurse into directories
            if os.path.isdir(item_path):
                print_directory_structure(item_path, output_file, indent + 1, max_depth)
    except PermissionError:
        # Skip directories we don't have permission to access
        error_line = '  ' * indent + "|- [Permission Denied]\n"
        if output_file:
            output_file.write(error_line)
        else:
            print(error_line, end="")

if __name__ == "__main__":
    # Input the root directory and output file name
    root_dir = input("Enter the root directory path: ").strip()
    save_to_file = input("Do you want to save the output to a file? (yes/no): ").strip().lower()

    # Input the maximum depth of scanning
    max_depth = input("Enter the maximum depth to scan (enter 0 for unlimited): ").strip()
    try:
        max_depth = int(max_depth)
        max_depth = None if max_depth == 0 else max_depth
    except ValueError:
        print("Invalid depth. Scanning with no depth limit.")
        max_depth = None

    if save_to_file == "yes":
        output_filename = input("Enter the output file name (e.g., structure.txt): ").strip()
        with open(output_filename, "w") as f:
            print_directory_structure(root_dir, output_file=f, max_depth=max_depth)
        print(f"Directory structure saved to {output_filename}")
    else:
        print_directory_structure(root_dir, max_depth=max_depth)
