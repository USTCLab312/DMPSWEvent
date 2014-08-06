'''
 *  $Id: SConstruct, 2014-08-06 18:16:31 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 24/07/2013
'''

import os
#--------------------------------------------------------------------
target='DmpEvent'
prefix=os.environ['DMPSWSYS']
includeDir="./include"

env = Environment(ENV = os.environ)
env.ParseConfig("root-config --cflags --libs")
env.Prepend(CPPPATH=[includeDir,prefix+'/include'])

# installation
#--------------------------------------------------------------------
for tmp in os.listdir(includeDir):
    if "." not in tmp[0] and "LinkDef" not in tmp and "Dictionary" not in tmp and ".h" in tmp:
        Default(Command(prefix+'/include/'+tmp,includeDir+'/'+tmp,Copy("$TARGET","$SOURCE")))

# main build
#--------------------------------------------------------------------
goal=env.SharedLibrary(target,Glob('./src/*.cc'))
Default(env.InstallAs(prefix+"/lib/lib"+target+".so",goal))

if env['PLATFORM'] == 'darwin':         # MacOs
    Default(env.InstallAs(prefix+"/lib/lib"+target+".dylib",goal))


