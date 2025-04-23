defmodule Exdemo do
  def fib(x) when x < 2 do
    1
  end

  def fib(x) do
    fib(x - 1) + fib(x - 2)
  end

  def timeFib(x) do
    {t, v} = :timer.tc(&fib/1, [x])
    IO.puts("Time: #{t / 1_000_000}s")
    v
  end

  def pmap(xs, op) do
    Enum.map(xs, fn x -> Task.async(fn -> op.(x) end) end)
    |> Enum.map(&Task.await/1)
  end

  def pmapFib() do
    {t, v} = :timer.tc(&pmap/2, [[42, 42, 42, 42, 42], &fib/1])
    IO.puts("Time: #{t / 1_000_000}s")
    v
  end
end
