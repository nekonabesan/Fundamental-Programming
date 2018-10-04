require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require '../modules/fp_module.rb'

=begin
演習 4 次のようなシミュレーションをやってみよ。
=end
class Fp08_04
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
  def c(n)
    begin
      raise ArgumentError if n.nil?
      result = 0.0
      cnt = 0
      a = 0
      b = 0
      c = 0
      n.times do
        a = rand(6)
        b = rand(6)
        c = rand(6)
        cnt += 1 if a == b || b == c || a == c
      end
      return ((cnt.to_s.to_d / n.to_s.to_d) * 100.0).to_i
    rescue => e
      return e
    end
  end


=begin
d. 次のようなすごろくをあがるのにサイコロを何回振るか分布を調べる。
升目20(0～19)
No.03 ５進む
No.07 No.17へ移動
No.11 １０戻る
No.13 ３進む
No.18 振り出し
=end
  def d(n)
    begin
      raise ArgumentError if n.nil?
      position = 0
      cnt = 0
      ds = 0
      results = Array.new
      n.times do
        cnt = 0
        position = 0
        while 19 >= position do
          position += rand(6)
          cnt += 1
          position += 5 if position == 3
          position = 17 if position == 7
          position -= 10 if position == 11
          position += 3 if position == 13
          position = 0 if position == 18
        end
        results.push(cnt)
      end
      return results
    rescue => e
      return e
    end
  end
end
