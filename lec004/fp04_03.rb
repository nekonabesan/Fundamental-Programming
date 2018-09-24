require 'bigdecimal'
require 'bigdecimal/util'

=begin
a. 2 × 2 行列の RPN 電卓を作れ。加減算、乗算は作ること。
=end
def a(array)

end

=begin
c. 2 × 2 より大きな 3 × 3、できれば一般の N × N 行列の RPN 電卓を作ってみよ。
=end
def add(array1,array2)
  begin
    raise ArgumentError if array1.nil? || array2.nil?
    raise ArgumentError if chk1(array1,array2) == false
    results = []
    array1.each_with_index do |row,i|
      line = Array.new(row.length)
      row.each_with_index do |col,j|
        line[j] = col + array2[i][j]
      end
      results.push(line)
    end
    return results
  rescue => e
    return e
  end
end

def sub()
end

def mul(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    raise ArgumentError if chk2(left,right) == false
    results = Array.new()
    left.each_with_index do |row,i|
      line = Array.new()
      for j in 0..(right[0].length - 1) do
        p = 0
        row.each_with_index do |col,k|
          p += col * right[k][j]
        end
        line.push(p)
      end
      results.push(line)
    end
    return results
  rescue => e
    return e
  end
end

=begin
b. さらに、転置行列、逆行列の演算も作ってみよ。
=end
def transpose(array)
  begin
    raise ArgumentError if array.nil?
    chk_ary = chk_ary(array)
    results = []
    for i in 0..(chk_ary['cols'] - 1) do
      results.push(Array.new(chk_ary['rows']))
    end
    array.each_with_index do |rows, i|
      rows.each_with_index do |row, j|
        results[j][i] = row
      end
    end
    return results
  rescue => e
    return e
  end
end


=begin

=end
def chk1(array1,array2)
  begin
    raise ArgumentError if array1.nil? || array2.nil?
    result = false
    array = [array1,array2]
    chk = [{'rows' => 0,'cols'=> Array.new},{'rows' => 0,'cols' => Array.new}]
    array.each_with_index do |items,i|
      chk[i]['rows'] = items.length
      items.each_with_index do |item,j|
        chk[i]['cols'][j] = item.length
      end
    end
    result = true if chk[0].flatten == chk[1].flatten
    return result
  rescue => e
    return e
  end
end
=begin
「左の列数」と「右の行数」が等しく
=end
def chk2(left,right)
  begin
    raise ArgumentError if left.nil? || right.nil?
    cols = 0
    left.each{|i| cols += 1 }
    rows = left.length
    result = false
    result = true if rows == cols
    return result
  rescue => e
    return e
  end
end

=begin
=end
def chk_ary(array)
  begin
    raise ArgumentError if array.nil?
    results = {'rows'=>0,'cols'=>0}
    array.each{|i| results['rows'] += 1 }
    results['cols'] = array[0].length
    return results
  rescue => e
    return e
  end
end
