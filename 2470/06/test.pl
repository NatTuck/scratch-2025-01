#!/usr/bin/perl
use 5.30.0;
use warnings FATAL => 'all';
use autodie;

use Test::Simple tests => 9;


my ($py,) = glob("*.py");
say("# Found code: $py");

my $pytest = qx(pytest -q "$py" | tail -n 1);
chomp $pytest;
say("# Ran tests: $pytest");

my $passed = 0;
if ($pytest =~ /(\d+) passed/) {
    $passed = $1;
}
my $failed = 0;
if ($pytest =~ /(\d+) failed/) {
    $failed = $1;
}

for my $ii (1..7) {
    ok($passed >= $ii, "$ii test passed");
}


ok($passed + $failed == 7, "7 tests run");

my $mypy = qx(mypy --disallow-untyped-defs --disable-error-code name-defined --follow-imports skip "$py" | tail -n 1);
my $errors = 0;
if ($mypy =~ /(\d+) errors/) {
    $errors = +$1;
}
ok($errors <= 8, "not too many type errors");
if ($errors > 8) {
    say "# Too many type errors: ($errors > 8)"
}

system("rm -rf __pycache__ .mypy_cache .pytest_cache sim/__pycache__");
