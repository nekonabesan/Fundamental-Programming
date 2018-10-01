require 'bigdecimal'
require 'bigdecimal/util'

def integ2(a,b,n)
  begin
    dx = (b - a).to_f / n
    s = 0.0
    n.times do |i|
      x = a + i * dx
      y = x**2
      s = s + y * dx
    end
    return s
  rescue => e
    return e
  end
end
