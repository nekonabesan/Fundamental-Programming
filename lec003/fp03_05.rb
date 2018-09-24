require 'bigdecimal'
require 'bigdecimal/util'

=begin
a. 数の配列を受け取り、その最大値を返す。
=end
def a(array)
  begin
    raise ArgumentError if array == nil
    result = array.shift.to_i
    array.each { |i| result = i.to_s.to_i if i.to_s.to_i > result.to_i  }
    return result
  rescue => e
    return e
  end
end

=begin
b. 数の配列を受け取り、最大値が何番目かを返す。なお先頭を 0 番目とし、最大値が複数あ
ればその最初の番号が答えであるとする。
=end
def b(array)
  begin
    raise ArgumentError if array == nil
    result = 0
    max = array.first.to_i
    array.each_with_index do |e,i|
      if e.to_i > max.to_i then
        max = e.to_i
        result = i
      end
    end
    return result.to_i
  rescue => e
    return e
  end
end

=begin
c. 数の配列を受け取り、最大値が何番目かを出力する。なお先頭を 0 番目とし、最大値が複
数あればそれらをすべて出力する。
=end
def c(array)
  begin
    raise ArgumentError if array == nil
    result = []
    max = array[b(array).to_i]
    array.each_with_index do |e,i|
      if e == max then
        result.push(i)
      end
    end
    return result
  rescue => e
    return e
  end
end

=begin
d. 数の配列を受け取り、その平均より小さい要素を出力する (例: 1、4、5、11 → 1、4、5)。
=end
def d(array)
  begin
    raise ArgumentError if array == nil
    result = []
    avg = avg(array)
    array.each_with_index do |e,i|
        result.push(e) if e.to_d < avg
    end
    return result
  rescue => e
    return e
  end
end

=begin
e. 数の配列を受け取り、その内容を「小さい順」に並べて出力する (例: 4, 11, 5, 1 → 1, 4,
5, 11)。
=end
def e(array)
  begin
    raise ArgumentError if array == nil
    result = []
    until array.empty?  do
      min = array.first
      index = 0
      array.each_with_index do |e,i|
          if min.to_s.to_d > e.to_s.to_d then
            min = e
            index = i.to_i
          end
      end
      array.delete_at(index.to_i)
      result.push(min)
    end
    return result
  rescue => e
    return e
  end
end


def avg(array)
  begin
    raise ArgumentError if array == nil
    result = 0.0;
    array.each_with_index do |e,i|
        result += e.to_s.to_d
    end
    return result / array.length.to_s.to_d
  rescue => e
    return e
  end
end
