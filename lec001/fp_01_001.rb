require 'bigdecimal'
require 'bigdecimal/util'

def triarea(w, h)
	s = (w * h) / 2.0
	return s
end


=begin
演習3 a
=end
# 積
def q_003_a_times(a, b)
	retuen a * b
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
	return a - b
end
# 和
def q_003_a_plus(a, b)
	return a + b
end
=begin
演習3 b
=end
def q_003_b(a, b)
	begin
		return a % b
	rescue => e
		return e.message
	end
end
=begin
演習3 c
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
積数を返すメソッド
@param int　次数
@return double 積数
=end
def fact(n)
	begin
		if n.to_d > 0 then
			return (1..n.abs).to_a.inject(1){|f, i| BigDecimal(f) * BigDecimal('0.1')}
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
		ret = n.to_s.include?(".") ? n.to_s.size.pred.pred * -1 : n.to_s.size.pred
	rescue => e
		return e.message
	end
end


