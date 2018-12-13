require __dir__ + '/fp08_04.rb'
require __dir__ + '/../lec007/fp07_01.rb'
require __dir__ + '/../modules/fp_module.rb'

#/===================================================/
# a. サイコロを 2 個振った目の合計の分布を調べる。
#/===================================================/
def a_bench(n = 100)
  begin
     raise ArgumentError if n.nil? || 1 > n
     obj = Fp08_04.new
     a = obj.a(n)
     avg = avalage(a)
     med = median(a)
     return {'avalage' => avg, 'median' => med}
  rescue => e
    return e
  end
end

#/===================================================/
# b. 60%の確率で表がでるイカサマコインで
#「10 回投げて表が出た回数の金額だけもらう」場合の金額の分布を調べる。
#/===================================================/
def b_bench(n = 100)
  begin
     raise ArgumentError if n.nil? || 1 > n
     obj = Fp08_04.new
     a = obj.b(n)
     avg = avalage(a)
     med = median(a)
     return {'avalage' => avg, 'median' => med}
  rescue => e
    return e
  end
end

#/===================================================/
# c. サイコロを 3 個振ってうち 2 個が同じ目 (もう 1 個は違う目)
# である確率がどれくらいか調べる。
#/===================================================/
def c_bench(n = 100)
  begin
     raise ArgumentError if n.nil? || 1 > n
     obj = Fp08_04.new
     result = obj.c(n)
     return result
  rescue => e
    return e
  end
end

#/===================================================/
# d. 次のようなすごろくをあがるのにサイコロを何回振るか分布を調べる。
#/===================================================/
def d_bench(n = 100)
  begin
    raise ArgumentError if n.nil? || 1 > n
    obj = Fp08_04.new
    a = obj.d(n)
    avg = avalage(a)
    med = median(a)
    return {'avalage' => avg, 'median' => med}
  rescue => e
    return e
  end
end

#/===================================================/
# 1回だけ実行
#/===================================================/
def d_bench2
  begin
    obj = Fp08_04.new
    a = obj.d(1)
    return a
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
