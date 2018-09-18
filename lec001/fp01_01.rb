require 'bigdecimal'
require 'bigdecimal/util'

=begin
演習 1
例題の三角形の面積計算メソッドをそのまま打ち込み、irb で実行させてみよ。
数字でないものを与えたりするとどうなるかも試せ。
=end
def triarea(w, h)
	begin
		return (w * h) / 2.0
	rescue =>
		return e
	end
end

=begin
演習 2 三角形の面積計算で、割る数の指定を「2.0」でなくただの「2」にした場合に何か違いがあ
るか試せ。
=end
begin triarea2(w,h)
	begin
		return (w * h) / 2
	rescue e
		retuen e
	end
end

=begin
演習3
=end
=begin
a. 2 つの実数を与え、その和を返す (ついでに、差、商、積も)。何か気づいたことがあれば
述べよ。
=end
# 積
def q_003_a_times(a, b)
	begin
		retuen a * b
	rescue => e
		return e
	end
end

# 商
def q_003_a_div(a, b)
	begin
		return a.quo(b).to_f
	rescue => e
		return e.message
	end
end
# 差
def q_003_a_diff(a, b)
	begin
		return a - b
	rescue => e
		retuen e
	end
end
# 和
def q_003_a_plus(a, b)
	begin
		return a + b
	rescue => e
		return e
	end
end

=begin
b. 「%」という演算子は剰余 (remainder) を求める演算である。上と同様に剰余もやってみ
よ。何か気づいたことがあれば述べよ。
=end
def q_003_b(a, b)
	begin
		return a % b
	rescue => e
		return e.message
	end
end

=begin
c. 数値 x を与え、逆数 1
x を出力する (分子は「1.0」という書き方にした方がいいかもしれない)。
=end
def q_003_c(x)
	begin
		num = ct_tos(x.abs)
		puts num

		deg = fact(num)
		puts num
		ret = num.negative? ? sprintf("%#.010g", x.to_d * deg.to_d) : sprintf("%#.010g", 1.to_d / x.to_d)
		return ret
	rescue => e
		return e.message
	end
end

=begin
d. 数値 x を与え、その 8 乗を返す。ついでに 6 乗、7 乗もやるとなおよい。
なお、Ruby のべき乗演算「**」は使わず、なおかつ乗除算が少ないことが望ましい。
第一引数の第二引数乗を返すメソッド
@param 実数
@param 整数
@return 実数
=end
def q_003_d(x, n)
	begin
		if n.to_d > 0 then
			return sprintf("%#.010g", (1..n.to_i.abs-1).to_a.inject(x.to_f){|f, i| f.to_f * x.to_f})
		else
			return Rational(1, (1..n.to_i.abs-1).to_a.inject(x.to_d){|f, i| f.to_f * x.to_f})
		end
	rescue => e
		e.message
	end
end

=begin
e. 円錐の底面の半径と高さを与え、体積を返す。
=end

=begin
f. 実数 x を与え、x の平方根を出力する。さまざまな値について計算し、精度がどれくらい
あるか検討せよ。
=end

=begin
=end

=begin
積数を返すメソッド
@param int　次数
@return double 積数
=end
def fact(n)
	begin
		if n.to_d > 0 then
			return (1..n.abs).to_a.inject(1){|f, i| f.to_s.to_d * '0.1'.to_d}
		else
			return (1..n.abs).to_a.inject(1){|f, i| f * 10}
		end
	rescue => e
		return e.message
	end
end

=begin
次数を返すメソッド
@param 実数(絶対値)
@return int 次数
=end
def ct_tos(n)
	begin
		ret = n.to_s.include?(".") ? n.to_s.size.pred * -1 : n.to_s.size.pred
	rescue => e
		return e.message
	end
end
