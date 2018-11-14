require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require '../modules/fp_module.rb'

#/===============================================================/
# 演習 3 モンテカルロ法で数値積分を行うときの、
# 精度 (有効桁数) と試行の数との関係について考察せよ。
# 円周率の例題を活用してもよいが、
# できれば別の関数を積分するプログラムを作って検討することが望ましい。
#/===============================================================/
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

#/===============================================================/
# テキストの回答例
# param int
# param floot
#/===============================================================/
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

#/===============================================================/
# モンテカルロ法/打点計数による1次元積分
# f(x) = -x^2+9
# param int
# return array
#/===============================================================/
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

#/===============================================================/
# モンテカルロ法/数値積分による1次元積分
# (参)https://rayspace.xyz/CG/contents/montecarlo/
# f(x) = -x^2+9
# param int
# return array
#/===============================================================/
def funcrand2(n)
  begin
    raise ArgumentError if n.nil?
    cnt = 0
    results = Array.new
    result = 0;
    intnum = 0;
    n.times do
      x = rand(-3.0...3.0)
      y = rand(0.0...9.0)
      intnum += (-1 * (x**2 - 9))
    end
    result = (6.0/n.to_f) * intnum.to_f
    results.push(result)
    if 36 < result then
      results.push(result - 36.0)
    else
      results.push(36.0 - result)
    end
    return results
  rescue => e
    return e
  end
end
