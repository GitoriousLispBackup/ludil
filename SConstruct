# general settings
project_name = 'ludil'
project_version = '0.1'
project_arch = 'x86-64'

# project directory settings
project_src = '#/src/'
project_obj = '#/obj/'
project_lib = '#/lib/'
project_inc = '#/inc/'
project_bin = '#/bin/'

# functions and settings
def Srcify(lst):
  return map ((lambda x: project_src+x),lst)
def Libify(lst):
  return map ((lambda x: project_lib+x),lst)

def PFile(name):
  return project_name+name

env = Environment (LIBPATH=project_lib, 
                   CPPPATH=project_inc)

# constructing the base library
libbasic_name = 'Basic'
libbasic_files = [PFile(libbasic_name+'Memory.c')]
libbasic_src = Srcify (libbasic_files)

env.SharedLibrary (Libify([PFile(libbasic_name)]), libbasic_src)

# libbasic test programs
libbasic_memoryTestName = libbasic_name+'MemoryTest'
env.Program(source=project_src+PFile(libbasic_memoryTestName+'.c'), LIBS=[PFile(libbasic_name)],
            target=project_bin+PFile(libbasic_memoryTestName))

# constructing the image library
libimage_name = 'Image'
libimage_files = [PFile(libimage_name+'PNG.c')] 
libimage_src = Srcify (libimage_files)

env.SharedLibrary (Libify([PFile(libimage_name)]), libimage_src) 

# test programs
libimage_testName = libimage_name+'Test'
env.Program(source=project_src+PFile(libimage_testName+'.c'), LIBS=[PFile(libimage_name),'png', PFile(libbasic_name)],
            target=project_bin+PFile(libimage_testName))
