import os
import platform

env = DefaultEnvironment()
target_platform = ARGUMENTS.get('platform', 'desktop')
mingw_path = ARGUMENTS.get('mingw_path', '/ProgramData/Chocolatey/bin')
arm_path = ARGUMENTS.get('arm_path', '/arm/latest/bin')
host_os = platform.system()

if host_os == "Windows":
    if target_platform == 'desktop':
        env.Tool('mingw')
        env.Replace(ENV={'PATH': os.getenv('MingwPath', mingw_path), 'TEMP': '/tmp'}, CC='gcc.exe', CXX='g++.exe', AR = 'ar.exe')
    elif target_platform == 'hardware':
        env.Tool('mingw')
        env.Replace(ENV = {'PATH': os.getenv('ArmPath', arm_path), 'TEMP' : '/tmp'}, CC = 'arm-none-eabi-gcc.exe', CXX = 'arm-none-eabi-g++.exe', AR = 'arm-none-eabi-ar.exe')
else:
    if target_platform == 'hardware':
        env.Replace(CC = 'arm-none-eabi-gcc', CXX = 'arm-none-eabi-g++', AR = 'arm-none-eabi-ar')

Export(['env', 'host_os', 'target_platform'])

env.SConscript("src/SConscript", variant_dir = f'build/{host_os}/{target_platform}/', duplicate = 0)
env.Default('src')

env.SConscript("test/SConscript", variant_dir= f'test/build/{host_os}/{target_platform}', duplicate = 0)