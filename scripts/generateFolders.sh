# $n = Command line argument n.
# $0 = script name
# $1 = set number
# $2 = exStart
# $3 = exEnd

if [[ -z "$1" ]]; then
    echo "Must provide arg 1 (set num) in environment" 1>&2
    exit 1
fi

if [[ -z "$2" ]]; then
    echo "Must provide arg 2 (ex start) in environment" 1>&2
    exit 1
fi

if [[ -z "$3" ]]; then
    echo "Must provide arg 3 (ex end) in environment" 1>&2
    exit 1
fi

mkdir set$1
cd set$1
cp ../common/metadata.txt metadata.txt
  sed -i "s/Z/$1/" metadata.txt

for ((i = $2; i <= $3; i++))
do
  leadingZero=''
  if (( i < 10 ))
  then
    leadingZero='0'
  fi
  folderName=$leadingZero$i
  
  echo "Making folder for: $folderName/"
  mkdir $folderName
  cd $folderName
  touch summary.txt
  cp ../../common/CMakeLists.txt ./CMakeLists.txt
  sed -i "s/Z/set$1/" CMakeLists.txt
  mkdir tests
  cp ../../common/main.cc ./tests/main.cc
  cp ../../common/main.ih ./tests/main.ih
  cp -r ../../common/Parser ./Parser
  cp -r ../../common/Scanner ./Scanner
  cd ..
done