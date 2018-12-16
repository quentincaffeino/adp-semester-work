#!python

import os, platform


def add_source(sources, name):
    sources.append(name)


def add_sources(sources, dir, extension):
    for root, directories, files in os.walk(dir):
        for file in files:
            if file.endswith('.' + extension):
                sources.append(root + '/' + file)


env = Environment()
host_platform = platform.system()
target_platform = ARGUMENTS.get('p', ARGUMENTS.get('platform', 'linux'))
target_arch = ARGUMENTS.get('a', ARGUMENTS.get('arch', '64'))
# default to debug build, must be same setting as used for cpp_bindings
target = ARGUMENTS.get('target', 'debug')
result_path = 'bin'
result_name = ARGUMENTS.get('n', ARGUMENTS.get('name', os.path.relpath('.', '..')))

result_name += '.linux.' + target_arch

env.Append(CCFLAGS=['-std=c99', '-g', '-O3', '-Wall', '-Wpedantic'])
if target == 'debug':
    env.Append(CCFLAGS=['-ggdb3'])

sources = []
add_sources(sources, 'src', 'c')

env.Program(target=result_path + '/' + result_name, source=sources)
