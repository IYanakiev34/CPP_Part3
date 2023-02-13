# $n = Command line argument n.
# $0 = script name
# $1 = set number
# $2 = exStart
# $3 = exEnd
# $4 = [exercisesToIgnore]

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

if [[ -z "$4" ]]; then
    echo "Must provide arg 4 (exercises to ignore) in environment" 1>&2
    echo "If no exercises to ignore, write none" 1>&2
    exit 1
fi

cd set$1

echo "Zipping"
touch mainOrder
createMainOrder.sh $2 $3
rm ../zips/set$1.zip
cat mainOrder | zip ../zips/set$1.zip -@
rm mainOrder
cd ..
removeEx.sh $1 $4

echo "Make sure that your order.txt files are modified (i.e: they do not include everything)"
echo "Email to submit@icce.rug.nl"