defmodule ExdemoTest do
  use ExUnit.Case
  doctest Exdemo

  test "greets the world" do
    assert Exdemo.hello() == :world
  end
end
