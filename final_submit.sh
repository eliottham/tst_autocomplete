
# Check files if they have been collected #

if [[ -f DictionaryBST.cpp ]] ; then
	echo "DictionaryBST.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: DictionaryBST.cpp. Exiting"
	exit
fi
if [[ -f DictionaryBST.h ]] ; then
	echo "DictionaryBST.h exists in directory"
else
	echo "MISSING REQUIRED FILE: DictionaryBST.h. Exiting"
	exit
fi
if [[ -f DictionaryHashtable.cpp ]] ; then
	echo "DictionaryHashtable.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: DictionaryHashtable.cpp. Exiting"
	exit
fi
if [[ -f DictionaryHashtable.h ]] ; then
	echo "DictionaryHashtable.h exists in directory"
else
	echo "MISSING REQUIRED FILE: DictionaryHashtable.h. Exiting"
	exit
fi
if [[ -f DictionaryTrie.cpp ]] ; then
	echo "DictionaryTrie.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: DictionaryTrie.cpp. Exiting"
	exit
fi
if [[ -f DictionaryTrie.h ]] ; then
	echo "DictionaryTrie.h exists in directory"
else
	echo "MISSING REQUIRED FILE: DictionaryTrie.h. Exiting"
	exit
fi
if [[ -f test.cpp ]] ; then
	echo "test.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: test.cpp. Exiting"
	exit
fi
if [[ -f util.cpp ]] ; then
	echo "util.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: util.cpp. Exiting"
	exit
fi
if [[ -f util.h ]] ; then
	echo "util.h exists in directory"
else
	echo "MISSING REQUIRED FILE: util.h. Exiting"
	exit
fi
if [[ -f benchhash.cpp ]] ; then
	echo "benchhash.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: benchhash.cpp. Exiting"
	exit
fi
if [[ -f benchdict.cpp ]] ; then
	echo "benchdict.cpp exists in directory"
else
	echo "MISSING REQUIRED FILE: benchdict.cpp. Exiting"
	exit
fi
if [[ -f FinalReport.pdf ]] ; then
	echo "FinalReport.pdf exists in directory"
else
	echo "MISSING REQUIRED FILE: FinalReport.pdf. Exiting"
	exit
fi
if [[ -f Makefile ]] ; then
	echo "Makefile exists in directory"
else
	echo "Please keep the provided 'Makefile' in the same directory as that of the code files."
	exit
fi
tar_file="PA2.tar"
tar_file_gz="PA2.tar.gz"
input_files="DictionaryBST.cpp DictionaryBST.h DictionaryHashtable.cpp DictionaryHashtable.h DictionaryTrie.cpp DictionaryTrie.h test.cpp util.cpp util.h benchdict.cpp benchhash.cpp FinalReport.pdf"

tar -zcvf $tar_file_gz $input_files
if [[ $? != 0 ]] ; then
    echo "Unable to create $tar_file_gz! Exit Code: $?"
    exit
else
    echo "Successfully created $tar_file_gz!"
fi

echo "Adding your extra dictionaries…"
echo "Please insert the name of the dictionary you would like to add -e.g ‘my_dictionary.txt’- otherwise insert ‘q’, without quotes and followed by [ENTER]:"
read dictionary

while [[ $dictionary != q ]]
do
	gunzip $tar_file_gz
	tar -rf $tar_file $dictionary
	gzip $tar_file
	echo "Please insert the name of the next dictionary you would like to add -e.g ‘my_dictionary.txt’- otherwise insert ‘q’, without quotes and followed by [ENTER]:"
	read dictionary
done

echo "You are all set! Upload PA2.tar.gz on TritionEd"

