require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require '../modules/fp_module.rb'

=begin
a. n^2 を計算するメソッドその 1
=end
def square1(n)
  begin
    raise AtgumentError if n.nil? || n.zero?
    return n * n
  rescue => e
    return e
  end
end

=begin
b. n^2 を計算するメソッドその 2
=end
def square2(n)
  begin
    raise AtgumentError if n.nil? || n.zero?
    n.times do result = result + n end
    return result
  rescue => e
    return e
  end
end

=begin
c. n^2 を計算するメソッドその 3
=end
def square3(n)
  begin
    raise AtgumentError if n.nil? || n.zero?
    result = 0
    n.times do
      n.times do
        result = result + 1
      end
    end
  rescue => e
    return e
  end
end

=begin
d. 1.0000000001^n を計算するメソッドその 1
=end
def near1pow1(n)
  begin
    raise AtgumentError if n.nil? || n.zero?
    result = 1.0
    n.times do result = result * 1.0000000001 end
    return result
  rescue => e
    return e
  end
end

=begin
e. 1.0000000001^n を計算するメソッドその 2
=end
def near1pow2(n)
  begin
    raise AtgumentError if n.nil? || n.zero?
    if n == 0
      return 1.0
    elsif n == 1
      return 1.0000000001
    elsif n % 2 > 0
      return near1pow2(n-1) * 1.0000000001
    else
      return near1pow2(n/2)**2
    end
  rescue => e
    return e
  end
end

=begin
f. 1.0000000001^n を計算するメソッドその 3
=end
def near1pow3(n)
  begin
    raise AtgumentError if n.nil? || n.zero?
    return Math.exp(n*Math.log(1.0000000001))
  rescue => e
    return e
  end
end

=begin
g. 1～3 の値が n 個並んだ全組み合わせを生成する
=end
def nest3n(n)
  begin
    raise AtgumentError if n.nil? || s.nil?
    nest3(n, "")
  rescue => e
    return e
  end
end

def nest3(n, s)
  begin
    raise AtgumentError if n.nil? || s.nil?
    if n <= 0 then
      # puts(s)
    else
      1.step(3) do |i| nest3(n-1, s + i.to_s) end
    end
  rescue => e
    return e
  end
end

=begin
h. 1～n の値のすべての順列を生成する
=end
def perm(n)
  begin
    raise AtgumentError if n.nil? || n.zero?
    a = Array.new(n) do |i| i+1 end
    perm1(a, [])
  rescue => e
    return e
  end
end

def perm1(a, b)
  begin
    raise AtgumentError if a.nil? || b.zero?
    if a.length == b.length
      # p(b)
    else
      a.each_index do |i|
        if a[i] != nil
            x = a[i]; a[i] = nil; b.push(x)
            perm1(a, b)
            a[i] = x; b.pop
        end
      end
    end
  rescue => e
    return e
  end
end
