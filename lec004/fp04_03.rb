require 'bigdecimal'
require 'bigdecimal/util'
require __dir__ + '/app/model/fp04_matrix.rb'

=begin
a. 2 × 2 行列の RPN 電卓を作れ。加減算、乗算は作ること。
=end
def a_add(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    obj = Matrix.new
    return obj.add(left,right)
  rescue => e
    return e
  end
end

def a_sub(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    obj = Matrix.new
    return obj.sub(left,right)
  rescue => e
    return e
  end
end

def a_mul(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    obj = Matrix.new
    return obj.mul(left,right)
  rescue => e
    return e
  end
end

=begin
b. さらに、転置行列、逆行列の演算も作ってみよ。
=end
def b(array)
  begin
    raise ArgumentError if array.nil?
    obj = Matrix.new
    return obj.transpose(array)
  rescue => e
    return e
  end
end


=begin
c. 2 × 2 より大きな 3 × 3、できれば一般の N × N 行列の RPN 電卓を作ってみよ。
=end
def c_add(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    obj = Matrix.new
    return obj.add(left,right)
  rescue => e
    return e
  end
end

def c_sub(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    obj = Matrix.new
    return obj.sub(left,right)
  rescue => e
    return e
  end
end

def c_mul(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    obj = Matrix.new
    return obj.mul(left,right)
  rescue => e
    return e
  end
end
