require 'bigdecimal'
require 'bigdecimal/util'

=begin
誤差あり
=end
def calc(a,b,c)
	begin
		result = Array.new

		if calc_d(a,b,c).negative? then
			raise "解なし"
		end
		result.push((-b.to_f - Math.sqrt(calc_d(a,b,c).to_f)) / (2.0 * a.to_f))
		result.push((-b.to_f + Math.sqrt(calc_d(a,b,c).to_f)) / (2.0 * a.to_f))

		return result
	rescue Exception => e
		return e.message
	end
end


def calc_d(a,b,c)
	begin
		return (b.to_f * b.to_f) - (4.to_f * a.to_f * c.to_f)
	rescue Exception => e
		return e.message
	end
end

=begin
誤差なし
=end
def calc2(a,b,c)
	begin
		result = Array.new

		if calc_d(a,b,c).negative? then
			raise "解なし"
		end



		if b > 0 then
			alpha = (b + Math.sqrt(calc_d2(a,b,c))) / (2.0 * a)
			result.push(-alpha)
			beta = c/(a * alpha)
			result.push(-beta)
			puts(result)
		else
			a = a * -1
			b = b * -1
			c = c * -1
			alpha = (-b - Math.sqrt(calc_d2(a,b,c))) / (2.0 * a)
			result.push(alpha)
			beta = c/(a * alpha)
			result.push(beta)
			puts(alpha) 
		end

		beta = c/(a * alpha)

		#result.push(alpha)
		#result.push(beta)

		return result
	rescue Exception => e
		return e.message
	end
end


def calc_d2(a,b,c)
	begin
		return (b * b) - (4 * a * c)
	rescue Exception => e
		return e.message
	end
end



#def calc1(x)
#	return Math.sqrt(x + 1.0) - 1.0
#end

#def calc2(x)
#	return x / (Math.sqrt(x + 1.0) + 1.0)
#end