#!/usr/bin/python3

import os
import shutil
import sys
import subprocess
import antlr  # Local

from glob import glob


# Important Directories
root_cwd = os.getcwd()
compiler_cwd = f'{root_cwd}/Compiler'
run_cwd = f'{compiler_cwd}/Run'


def modify_vscode_tasks(gcc_commands: [str]): # Needs to be refactored for C + C++ code.
    tasks_json_path = f'{root_cwd}/.vscode/tasks.json'
    # Retrieve All Lines of tasks.json
    with open(tasks_json_path, 'r') as file:
        lines = file.readlines()
    # Create G++ Arguments (gcc_commands should start at index 1)
    try:
        with open(tasks_json_path, 'w') as file:
            line_strip = '\n\r\t '
            in_args = False
            wrote_args = False
            for line in lines:
                if not in_args:
                    if not wrote_args and line.strip(line_strip) == '"args": [':
                        in_args = True
                    file.write(line)  # Write Line as-is
                elif in_args and not wrote_args:
                    wrote_args = True
                    for gcc_command in gcc_commands[1:]:  # Start at Index 1 to Skip 'gcc' in Commands
                        file.write(f'        "{gcc_command}",\n')  # Has Eight Spaces For Proper Indentation
                else:
                    if line.strip(line_strip) == '],':
                        in_args = False
                        file.write(line)  # Write Line as-is
    except IOError as ex:
        print(ex)
        with open(tasks_json_path, 'w') as file:
            for line in lines:
                file.write(line)


def compile_cpp():
    # Find All Source Files
    source_files = glob('**/*.cpp', recursive=True)
    if len(source_files) <= 0:
        return
    # Generate G++ Command
    gpp_command = ['g++', '-g', '-Wall', '-Wno-comment', '-Wno-switch', '-std=c++20',
                   '-IRun/include/', '-DANTLR4CPP_STATIC', '-fvisibility=hidden',
                   '-fdiagnostics-color=always', '-c']
    # Format Grammar Include Dirs
    include_dirs = []
    for grammar_dir in os.listdir(f'{root_cwd}/Grammar/'):
        if not os.path.isdir(grammar_dir):
            continue
        include_dirs.append(f'-I{grammar_dir}/')
    # Extend Source Files, Include Paths, and Libraries to Command
    gpp_command.extend(include_dirs)  # Include Dirs
    gpp_command.extend(source_files)
    gpp_command.extend(['-LRun/', '-lantlr4-runtime'])
    # Run Command
    subprocess.run(gpp_command)


def compile_c():
    # Find All Source Files
    source_files = glob('**/*.c', recursive=True)
    if len(source_files) <= 0:
        return
    # Generate Gcc Command
    gcc_command = ['gcc', '-g', '-Wall', '-Wno-comment', '-Wno-switch',
                   '-fvisibility=hidden', '-fdiagnostics-color=always', '-c']
    # Extend Source Files to Command
    gcc_command.extend(source_files)
    # Run Command
    subprocess.run(gcc_command)


def link_objects():
    # Find All Object Files
    object_files = glob('**/*.o', recursive=True)
    if len(object_files) <= 0:
        return
    # Run Link Command
    gcc_link_command = ['g++', '-g', '-Wall', '-o', 'Build/storys', '-fvisibility=hidden',
                        '-fdiagnostics-color=always']
    # Extend Object Files to Command
    gcc_link_command.extend(object_files)
    gcc_link_command.extend(['-LRun/', '-lantlr4-runtime'])
    # Run Command
    subprocess.run(gcc_link_command)


def compile_source():
    # Compile Runtime If Needed
    if not os.path.isdir(run_cwd):
        if not os.path.isdir('antlr4/'):  # Clone and Compile Repo (Cpp) (If Needed)
            antlr.clone_repo()
            antlr.compile_cpp()
        antlr.compile_cpp_runtime()
    # Compile ByteCodeTranslator
    os.chdir(compiler_cwd)
    # Compile
    compile_cpp()
    compile_c()
    link_objects()
    for object_file_path in glob('*.o'):
        os.remove(object_file_path)
    # Return to Root CWD
    os.chdir(root_cwd)


def process_grammar():
    os.chdir('Grammar/')
    grammar_dirs = os.listdir(os.getcwd())
    for grammar_dir in grammar_dirs:
        grammar_output_dir = f'{compiler_cwd}/{grammar_dir}'
        # Delete Old Data
        if os.path.isdir(grammar_output_dir):
            shutil.rmtree(grammar_output_dir)
            os.mkdir(grammar_output_dir)
        else:
            os.mkdir(grammar_output_dir)
        # Construct Arguments
        grammar_files = glob(f'{os.getcwd()}/{grammar_dir}/*.g4')
        antlr_args = ['-o', grammar_output_dir, '-Dlanguage=Cpp', '-no-listener', '-visitor']
        antlr_args.extend(grammar_files)
        # Run Antlr
        antlr.run_antlr(antlr_args)
        # Leave Grammar Dir
        os.chdir(root_cwd)


def rebuild():
    clean()
    # Delete Antlr Runtime
    if os.path.isdir(run_cwd):
        shutil.rmtree(run_cwd)


def clean():  # Stuff To Clean Up After Compilation
    # Delete Antlr Repo
    if os.path.isdir('antlr4/'):
        shutil.rmtree('antlr4/')


def process_args():
    args = {
        'rebuild': False, 'clean': False, 'compile_only': False
    }
    # Exit function early if there are no arguments
    if len(sys.argv) == 0:
        return args
    # Loop through and process arguments
    for i, v in enumerate(sys.argv):
        if v == '--rebuild':
            args['rebuild'] = True
        elif v == '--clean':
            args['clean'] = True
        elif v == '--compile_only':
            args['compile_only'] = True
    # Return Processed Args
    return args


def main():
    args = process_args()
    # Do Full Rebuild if Necessary
    if args['rebuild']:
        rebuild()
    # Compile Antlr Files
    if not args['compile_only']:
        process_grammar()
    # Always Compile Source Files
    compile_source()
    # Do Cleanup if necessary
    if args['clean']:
        clean()


if '__main__' == __name__:
    main()
