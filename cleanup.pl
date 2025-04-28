#!/usr/bin/perl
use 5.30.0;
use warnings FATAL => 'all';
use autodie;

my @courses = qw(2470 4310);

for my $course (@courses) {
    my @paths = `find "$course" -type f`;
    for my $path (@paths) {
        chomp $path;
        my $type = `file "$path"`; 
        if ($type =~ /ELF 64-bit/ || $type =~ /compiled Java class data/) {
            say("[$path] $type"); 
            if (length($path) > 5) {
                system(qq{rm -v "$path"});
            }
        }
    }
}
