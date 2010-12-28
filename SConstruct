# -----------------------------------------------------------
# Ludil construction file
# -----------------------------------------------------------
# Author: Josef P. Bernhart
# Date:   28-12-2010
# -----------------------------------------------------------


# -----------------------------------------------------------
# general settings
# -----------------------------------------------------------
project_name = 'ludil'
project_version = '0.1'
project_arch = 'x86-64'
# -----------------------------------------------------------

# -----------------------------------------------------------
# project directory settings
# -----------------------------------------------------------
project_src = '#/src/'
project_obj = '#/obj/'
project_lib = '#/lib/'
project_inc = '#/inc/'
project_bin = '#/bin/'
# -----------------------------------------------------------

# -----------------------------------------------------------
# functions and settings
# -----------------------------------------------------------
def Srcify(lst):
  return map ((lambda x: project_src+x),lst)

def Libify(lst):
  return map ((lambda x: project_lib+x),lst)

def PFile(name):
  return project_name+name

env = Environment (LIBPATH=project_lib, 
                   CPPPATH=project_inc)

def libraryTest(libraryName, name):
  testName = libraryName+name
  env.Program(source=project_src+PFile(testName+'.c'), 
              LIBS=[PFile(libraryName)],
              target=project_bin+PFile(testName))

def moduleLibrary(moduleName, files):
  libFiles = map ((lambda x: PFile(moduleName+x)), files)
  libSrc = Srcify (libFiles)
  env.SharedLibrary (Libify([PFile(moduleName)]), libSrc)
# -----------------------------------------------------------

# -----------------------------------------------------------
# constructing the base library
# -----------------------------------------------------------
libbasic_name = 'Basic'
libbasic_files = ['Memory.c',
                  'Io.c',
                  'String.c',
                  'Point.c',
                  'Bitmask.c']
moduleLibrary (libbasic_name, libbasic_files)
# -----------------------------------------------------------

# -----------------------------------------------------------
# libbasic test programs
# -----------------------------------------------------------
libraryTest (libbasic_name, 'MemoryTest')
libraryTest (libbasic_name, 'IoTest')
libraryTest (libbasic_name, 'PointTest')
libraryTest (libbasic_name, 'BitmaskTest')
# -----------------------------------------------------------

# -----------------------------------------------------------
# constructing the image library
# -----------------------------------------------------------
libimage_name = 'Image'
libimage_files = ['PNG.c'] 
moduleLibrary (libimage_name, libimage_files)
# -----------------------------------------------------------

# -----------------------------------------------------------
# test programs
# -----------------------------------------------------------
libimage_testName = libimage_name+'Test'
env.Program(source=project_src+PFile(libimage_testName+'.c'), 
            LIBS=[PFile(libimage_name), 
            'png', 
            PFile(libbasic_name)],
            target=project_bin+PFile(libimage_testName))
# -----------------------------------------------------------

# -----------------------------------------------------------
# constructing the shell library
# -----------------------------------------------------------
libshell_name = 'Shell'
libshell_files = [PFile('Shell.c')]
libshell_src = Srcify (libshell_files)

env.SharedLibrary (Libify([PFile(libshell_name)]), libshell_src)
# -----------------------------------------------------------
