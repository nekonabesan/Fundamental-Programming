require './fp02_06'
require 'bigdecimal'
require 'bigdecimal/util'

def main(n)
  begin
    obj = Fp02_06.new
    n = n.to_i.abs
    result = []
    for i in 2..n do
      result.push(i) if obj.p(i)
    end
    return result
  rescue => e
    return e.message
  end
end
