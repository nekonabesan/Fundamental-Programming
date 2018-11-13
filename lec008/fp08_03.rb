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
    count = 0
    n.times do
      x = rand()
      y = rand()
      puts(x**2)
      count = count + 1 if  y <= -((x**2) - 9)
    end
    return count
  rescue => e
    return e
  end
end
