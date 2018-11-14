require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require '../modules/fp_module.rb'

=begin
演習 3 モンテカルロ法で数値積分を行うときの、精度 (有効桁数) と試行の数との関係について考察
せよ。円周率の例題を活用してもよいが、できれば別の関数を積分するプログラムを作って検
討することが望ましい。
=end
def pirandom(n)
  begin
    raise ArgumentError if n.nil?
    count = 0
    n.times do
      x = rand()
      y = rand()
      count = count + 1 if x**2 + y**2 < 1.0
    end
    return 4.0 * count / n
  rescue => e
    return e
  end
end

def integrandom(n)
  begin
    raise ArgumentError if n.nil?
    count = 0
    n.times do
      x = rand()
      y = rand()
      if y < x then
        count = count + 1
      end
    end
    return count / n.to_f
  rescue => e
    return e
  end
end

def funcrand1(n)
  begin
    raise ArgumentError if n.nil?
    cnt = 0
    results = Array.new
    n.times do
      x = rand(-3.0...3.0)
      y = rand(0.0...9.0)
      if y <= (-1 * (x**2 - 9)) then
        cnt += 1
      end
    end
    result = ((1.0/n.to_f) * cnt.to_f * 54.0)
    results.push(result)
    if 36 < result then
      results.push(result - 36)
    else
      results.push(36 - result)
    end
    return results
  rescue => e
    return e
  end
end
