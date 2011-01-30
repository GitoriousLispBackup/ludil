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
project_doc = '#/doc/'
project_config = '#/'
# -----------------------------------------------------------

# -----------------------------------------------------------
# custom builders
# -----------------------------------------------------------
# ...

# -----------------------------------------------------------
# general environment settings
# -----------------------------------------------------------
debug_flags = '-g -ggdb'
cflags = ''

if 'debug' in COMMAND_LINE_TARGETS:
  cflags = cflags+debug_flags

env = Environment (LIBPATH=[project_lib], 
                   CPPPATH=project_inc,
                   LIBS='dl',
                   CFLAGS=cflags,
                   tools = ["default", "doxygen"], 
                   toolpath = '.')

# -----------------------------------------------------------
# functions and settings
# -----------------------------------------------------------
def PrintSection(text):
  print "-----------------------------------------------------------"
  print 'Building '+text
  print "-----------------------------------------------------------"

def Srcify(lst):
  return map ((lambda x: project_src+x),lst)

def Libify(lst):
  return map ((lambda x: project_lib+x),lst)

def PFile(name):
  return project_name+name


testObj = env.Object(project_obj+project_name+'Test',
                     project_src+project_name+'Test')

def libraryTest(libraryName, name):
  testName = libraryName+name
  env.Program(source=[project_src+PFile(testName+'.c'),
              testObj], 
              LIBS=[PFile(libraryName)],
              target=project_bin+PFile(testName))

def moduleLibrary(moduleName, files):
  libFiles = map ((lambda x: PFile(moduleName+x)), files)
  libSrc = Srcify (libFiles)
  env.SharedLibrary (Libify([PFile(moduleName)]), libSrc )

def pluginLibrary(pluginName, files):
  libFiles = map ((lambda x: PFile('Plugin'+pluginName+x)), ['Main.c']+files)
  libSrc = Srcify (libFiles)
  env.SharedLibrary (Libify([PFile('Plugin'+pluginName)]), libSrc)
# -----------------------------------------------------------

# -----------------------------------------------------------
# constructing the base library
# -----------------------------------------------------------
PrintSection ('basic functionality library')
libbasic_name = 'Basic'
libbasic_files = ['Memory.c',
                  'Io.c',
                  'String.c',
                  'Point.c',
                  'Bitmask.c',
                  'Blob.c',
                  'Kernel.c']
moduleLibrary (libbasic_name, libbasic_files)
# -----------------------------------------------------------

# -----------------------------------------------------------
# libbasic test programs
# -----------------------------------------------------------
PrintSection ('testprograms for the basic functionality library')
libraryTest (libbasic_name, 'MemoryTest')
libraryTest (libbasic_name, 'IoTest')
libraryTest (libbasic_name, 'PointTest')
libraryTest (libbasic_name, 'BitmaskTest')
libraryTest (libbasic_name, 'BlobTest')
libraryTest (libbasic_name, 'KernelTest')

# create the plugin test library, so the library for testing
# the plugin subsystem
PrintSection ('plugins')
pluginLibrary ('Test', [])
# -----------------------------------------------------------

# -----------------------------------------------------------
# constructing the image library
# -----------------------------------------------------------
PrintSection ('image format handling library')
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

# -----------------------------------------------------------
# documentation
# -----------------------------------------------------------
# -----------------------------------------------------------
