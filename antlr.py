import os
import subprocess
import shutil

from build import run_cwd


def run_antlr(args: []):
    commands = [
            'java',
            '-Xmx500M',
            '-cp',
            '".:/usr/local/lib/antlr-4.9.3-complete.jar:$CLASSPATH"',
            'org.antlr.v4.Tool'
        ]
    commands.extend(args)
    subprocess.run(commands)


def clone_repo():
    # Clones Repo into CWD
    subprocess.run(['git', 'clone', '--recursive', 'https://github.com/antlr/antlr4.git', '--branch', '4.9.3'])


def compile_cpp():
    # Check if Path Exists
    if not os.path.isdir('antlr4/'):
        return
    # Navigate to Cpp
    old_cwd = os.getcwd()  # Retain Old CWD
    os.chdir('antlr4/runtime/Cpp/')
    # Compile Cpp
    os.mkdir('build')
    os.mkdir('run')
    os.chdir('build/')
    subprocess.run(['cmake', '..'])
    subprocess.run(['make'])
    # Return to Old CWD
    os.chdir(old_cwd)


def compile_cpp_runtime():
    # Check if Path Exists
    if not os.path.isdir('antlr4/'):
        return
    # Navigate to Cpp/build
    old_cwd = os.getcwd()  # Retain Old CWD
    os.chdir('antlr4/runtime/Cpp/build')
    # Compile Cpp Runtime
    subprocess.run(['make', f'DESTDIR={run_cwd}', 'install'])
    # Move Appropriate Files and Directories
    os.mkdir(f'{run_cwd}/include')  # Create Include Directory
    shutil.move(f'{run_cwd}/usr/local/include/antlr4-runtime/', run_cwd)
    shutil.move(f'{run_cwd}/usr/local/lib/libantlr4-runtime.a', f'{run_cwd}/libantlr4-runtime.a')
    for file in os.listdir(f'{run_cwd}/antlr4-runtime/'):
        shutil.move(f'{run_cwd}/antlr4-runtime/{file}', f'{run_cwd}/include/{file}')
    # Delete Unnecessary Files and Directories
    shutil.rmtree(f'{run_cwd}/usr/')
    shutil.rmtree(f'{run_cwd}/antlr4-runtime/')
    # Return to Old CWD
    os.chdir(old_cwd)
