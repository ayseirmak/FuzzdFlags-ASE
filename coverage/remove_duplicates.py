import sys
import re

def remove_duplicates(input_file, output_file):
    with open(input_file, 'r') as file:
        content = file.read()

    entries = content.split('----------------------------------------\n')
    unique_entries = set()
    final_entries = []

    for entry in entries:
        source_match = re.search(r'Source File: (.+)', entry)
        flags_match = re.search(r'Flags: (.+)', entry, re.DOTALL)

        if source_match and flags_match:
            source = source_match.group(1).strip()
            flags = flags_match.group(1).strip()
            key = (source, flags)

            if key not in unique_entries:
                unique_entries.add(key)
                final_entries.append(entry.strip())

    with open(output_file, 'w') as file:
        file.write('\n----------------------------------------\n'.join(final_entries))

    print(f"Duplicate entries removed. Output written to {output_file}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python remove_duplicates.py <input_file> <output_file>")
        sys.exit(1)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    remove_duplicates(input_file, output_file)
