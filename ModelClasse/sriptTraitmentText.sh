#! /bin/usr

touch link.txt;
touch h1.txt;
touch h2.txt;
touch h3.txt;

rm link.txt;
rm h1.txt;
rm h2.txt;
rm h3.txt;

touch link.txt;
touch h1.txt;
touch h2.txt;
touch h3.txt;


for line in (cat temp.txt)
do
  grep '<a*</a>' $line | grep 'href=\"*\"' | grep '\"*\"' >> link.txt; echo "\n" >> link.txt;
  grep '<h1></h1>' $line | grep '>*<' >> h1.txt; echo "\n" >> h1.txt;
  grep '<h2></h2>' $line | grep '>*<' >> h2.txt; echo "\n" >> h2.txt;
  grep '<h3></h3>' $line | grep '>*<' >> h3.txt; echo "\n" >> h2.txt;
done