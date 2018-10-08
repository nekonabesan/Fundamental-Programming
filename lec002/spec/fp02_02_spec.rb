require __dir__ + "/spec_helper"
require __dir__ + '/../fp02_02.rb'

describe "演習2" do
=begin
 a. 2 つの異なる実数 a、b を受け取り、より大きいほうを返す。
=end
  context "a"do
    it "a(10.100000001,0)" do
      results = a(10.100000001,0)
      expect(results).to eq 10.100000001
    end
    it "a(1,nil)" do
      results = a(1,nil)
      expect(results).to eq 1
    end
    it "a(0,-1)" do
      results = a(0,-1)
      expect(results).to eq 0
    end
    it "a(-9999,88888888)" do
      results = a(-9999,88888888)
      expect(results).to eq 88888888
    end
  end
  context "b" do
=begin
  b. 3 つの異なる実数 a、b、c を受け取り、最大のものを返す。(やる気があったら 4 つでやっ
  てみてもよいでしょう。)
=end
    it "b(1,-5,8.0)" do
      results = b(1,-5,8.0)
      expect(results).to eq 8.0
    end
    it "b(0,-5,nil)" do
      results = b(0,-5,nil)
      expect(results).to eq 0
    end
    it "b(1,-5,8.0)" do
      results = b(0.01,0.000000125,-2.0)
      expect(results).to eq 0.01
    end
    it "b(-99999,0,10000000000)" do
      results = b(-99999,0,10000000000)
      expect(results).to eq 10000000000
    end
  end
  context "c" do
=begin
  c. 実数を 1 つ受け取り、それが正なら「’positive’」、負なら「’negative’」、零なら
  「’zero’」という文字列を返す。(注意! 文字列は’…’ または"…"で囲んで指定します。)
=end
    it "c(-0.00000000125)" do
      results = c(-0.00000000125)
      expect(results).to eq "negative"
    end
    it "c(nil)" do
      results = c(nil)
      expect(results).to eq "zero"
    end
    it "c(nil)" do
      results = c(0.0)
      expect(results).to eq "zero"
    end
    it "c(8)" do
      results = c(8)
      expect(results).to eq "positive"
    end
  end
end
