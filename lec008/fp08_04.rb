require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require '../modules/fp_module.rb'

=begin
演習 4 次のようなシミュレーションをやってみよ。
=end

=begin
a. サイコロを 2 個振った目の合計の分布を調べる。
=end
def a(n)
  begin
    raise ArgumentError if n.nil?
    results = Array.new
    n.times do
      results.push((rand(6) + 1) + (rand(6) + 1))
    end
    return results
  rescue => e
    return e
  end
end

=begin
b. 60%の確率で表がでるイカサマコインで「10 回投げて表が出た回数の金額だけもらう」場
合の金額の分布を調べる。
=end
def b(n)
  begin
    raise ArgumentError if n.nil?
    results = Array.new
    n.times do

    end
  rescue => e
    return e
  end
end

=begin
c. サイコロを 3 個振ってうち 2 個が同じ目 (もう 1 個は違う目) である確率がどれくらいか調
べる。
=end


=begin
d. 次のようなすごろくをあがるのにサイコロを何回振るか分布を調べる。
=end
