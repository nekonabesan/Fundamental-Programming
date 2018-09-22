require 'bigdecimal'
require 'bigdecimal/util'

=begin
誤差あり
=end
def calc_a(a,b,c)
	begin
		result = Array.new
		if calc_d(a,b,c).negative? then
			raise "解なし"
		end
		result.push((-b.to_f - Math.sqrt(calc_d(a,b,c).to_f)) / (2.0 * a.to_f))
		result.push((-b.to_f + Math.sqrt(calc_d(a,b,c).to_f)) / (2.0 * a.to_f))
		return result
	rescue Exception => e
		return e
	end
end


def calc_d(a,b,c)
	begin
		return (b.to_f * b.to_f) - (4.to_f * a.to_f * c.to_f)
	rescue Exception => e
		return e
	end
end

=begin
c. 仮に b ≥ 0 とする (負なら a, b, c すべてに −1 を掛ければ解は同じで b ≥ 0 とできる)。す
ると、± のうち − については両方の符号が同じなので桁落ちなしに解が求まる。これを α
とおき、解と係数の関係 αβ =
c
a を利用して他方の解 β を求めることができる。この方法
で 2 つの解を求めて打ち出す (または「[値, 値]」の形で返す) メソッドを作成しなさい。
いくつかの値で実行例を示すこと。
=end
def calc_c(a,b,c)
	begin
		result = Array.new
		if calc_d(a,b,c).negative? then
			raise "解なし"
		end
		if b >= 0 then
			alpha = (b + Math.sqrt(calc_d2(a,b,c))) / (2.0 * a)
			result.push(-alpha)
			beta = c/(a * alpha)
			result.push(-beta)
		else
			a = a * -1
			b = b * -1
			c = c * -1
			alpha = (-b - Math.sqrt(calc_d2(a,b,c))) / (2.0 * a)
			result.push(alpha)
			beta = c/(a * alpha)
			result.push(beta)
		end
		beta = c/(a * alpha)
		return result
	rescue Exception => e
		return e.message
	end
end


def calc_d2(a,b,c)
	begin
		return (b * b) - (4 * a * c)
	rescue Exception => e
		return e
	end
end



#def calc1(x)
#	return Math.sqrt(x + 1.0) - 1.0
#end

#def calc2(x)
#	return x / (Math.sqrt(x + 1.0) + 1.0)
#end
