@newList = (); # list to store first occurence

# function to check whether an element present in nw list or not
# if present return 1, otherwise return 0
sub has {
    for my $var (@newList){
        if ($var eq $_[0]){
            return 1;
        }
    }
    return 0;
}

# find and store first occurence
for my $var (@ARGV){
    if (has($var) == 0){
        push(@newList, $var); # push into new list
    }
}

# print new list
for my $var (@newList){
    print "$var "
} 

