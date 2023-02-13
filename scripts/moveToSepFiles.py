#!/usr/bin/env python

# Very rudimentary. Should really only contain internal header include (as first line) + function sigs + empty bodies

# Creates function files + outputs the files created

# TODO: Avoid overwriting existing files

import os
import sys

class Function:
  def __init__(self, line, header, folder):
    self.signature = line
    self.no = -1
    self.header = header
    self.folder = folder

    removedScope = self.signature.split("::")

    if (len(removedScope) >= 2):
      afterScope = removedScope[1]
      self.name = afterScope.split("(")[0]
    else:
      beforeArgs = line.split("(")[0]
      afterType = beforeArgs.split(" ")[1]
      self.name = removeFrontOp(afterType)

def removeFrontOp(afterType):
  while (str.isalpha(afterType[0])):
    afterType = afterType[1:]
  return afterType

def main():
  cppFiles = getCPPFiles()

  for cppFile in cppFiles:
    functions = getFunctions(cppFile)

    toAddToCMakeList = ""

    for function in functions:
      toAddToCMakeList += createFunctionFile(function) + " "

    print(toAddToCMakeList)

def getCPPFiles():
  return sys.argv[1:]

def isCPPFile(filename):
  return filename.endswith(".cc")

def getFunctions(cppFile):
  functions = []
  with open(cppFile, 'r') as file:
    lines = [line.rstrip() for line in file]
    internalHeader = lines[0]
    for line in lines[1:]:
      if (isSignature(line)):
        functions += [Function(line, internalHeader, os.path.dirname(cppFile))]

  addFuncNo(functions)

  return functions

def addFuncNo(functions):
  uniqueNames = set([f.name for f in functions])
  nameCounts = {}

  for functionName in uniqueNames:
    nameCounts[functionName] = 0

  for function in functions:
    nameCounts[function.name] += 1
    function.no = nameCounts[function.name]

  for name in nameCounts:
    removeUnnecessaryFunNums(name, nameCounts[name], function, functions)

def removeUnnecessaryFunNums(name, count, function, functions):
  if (count == 1):
    for function in functions:
      if (function.name == name):
        function.no = ""

def isSignature(line):
  if (line.strip()):
    return not (
      ("{" in line) or ("}" in line)
    )
  return False

def createFunctionFile(function):
  if ("operator" in function.name):
    print("Give new name for: " + function.name)
    inp = input()

    if (">" in function.name or "<" in function.name or "*" in function.name or "/" in function.name or "&" in function.name):
      while (not inp.strip()):
        print("You need new name for: " + function.name)
        inp = input()

    if (inp.strip()):
      function.name = inp
    else:
      function.name = function.name.replace("operator", "op")
      print("Using default name: " + function.name)

  path = function.folder + "/" + function.name + str(function.no) + ".cc";
  with open(path, "w") as f:
    f.write(function.header)
    f.write("\n\n")
    f.write(function.signature)
    f.write("\n{\n\n}")

  return path

if __name__ == "__main__":
  main()