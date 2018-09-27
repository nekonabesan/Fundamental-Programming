require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'


def radixsort(a)
  begin
    raise ArgumentError if a.nil?

    mask = 1
    flg = true
    while flg == true do
      flg = false
      left = Array.new
      right = Araay.new
      a.each_with_index do |val,i|
        if val & mask == 0 then
          left.push(val)
        else
          left.push(val)
          flg = true
        end
        mask = mask << 1
      end
      a = Array.new
      a.push(left)
      a.push(right)
    end

  rescue => e
    return e
  end
end
