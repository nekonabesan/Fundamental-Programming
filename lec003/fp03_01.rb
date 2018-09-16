require 'bigdecimal'
require 'bigdecimal/util'

def fizz1
  100.times do |i|
    if i % 3 == 0
      puts('fizz')
    else
      puts(i)
    end
  end
end

=begin
a. 0 から 99 までの数のうち、2 の倍数でも 3 の倍数でもないものだけを順に打ち出す。
=end
def a
  begin
    result = []
    for i in 0..99 do
      result.push(i) if i % 2 != 0 && i % 3 != 0
    end
    return result
  rescue => e
    return e
  end
end

=begin
b. 0 から 99 までの数を順に打ち出すが、ただし 3 の倍数の時は fizz、5 の倍数の時は buzz、
3 の倍数かつ 5 の倍数の時は fizzbuzz と (数値の代わりに) 打ち出す (fizzbuzz 問題)。
=end
def b
  begin
    result = []
    for i in 0..99 do
      if i % 3 == 0 && i % 5 == 0 then
        result.push('fizzbuzz')
      elsif i % 5 == 0 then
        result.push('buzz')
      elsif i % 3 == 0 then
        result.push('fizz')
      else
        result.push(i)
      end
    end
    return result
  rescue => e
    return e.message
  end
end

=begin
c. 0 から 99 までの数を順に打ち出すが、ただし 3 の倍数と 3 がつく数字の時は数値の代わり
に aho と打ち出す。
=end
def c
  begin
    result = []
    for i in 0..99 do
      if i % 3 == 0 then
        result.push('aho')
      elsif i.to_s.match("3$") then
        result.push('aho')
      else
        result.push(i)
      end
    end
    return result
  rescue => e
    return e.message
  end
end
