require __dir__ + '/fp08_04.rb'
require __dir__ + '/../lec007/fp07_01.rb'
require __dir__ + '/../modules/fp_module.rb'

def d_bench
  begin
    obj = Fp08_04.new
    a = obj.d(100)
    avg = avalage(a)
    med = median(a)
    results = {'avalage' => avg, 'median' => med, 'result' => a}
  rescue => e
    return e
  end
end

def avalage(a)
  begin
    raise ArgumentError if a.nil?
    l = a.size - 1
    sum = 0
    a.each_with_index{|val,i| sum += val}
    return sum / l
  rescue => e
    return e
  end
end

def median(a)
  begin
    raise ArgumentError if a.nil?
    l = a.size - 1
    b = selectionsort(a)
    result = 0
    if l % 2 == 0 then
      result = (b[l / 2] + b[(l / 2) + 1]) / 2
    else
      result = b[l / 2]
    end
    return result
  rescue => e
    return e
  end
end
