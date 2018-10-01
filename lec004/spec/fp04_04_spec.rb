require __dir__ + "/spec_helper"
require __dir__ + '/../fp04_04.rb'

describe "演習4" do
  before do
  end
  context "gcd 1" do
    it "gcd" do
      results = gcd(21,27)
      expect(results).to match(3)
    end
  end
end
describe "演習4" do
  before do
  end
  context "gcd 2" do
    it "gcd" do
      results = gcd(24,36)
      expect(results).to match(12)
    end
  end
end
describe "演習4" do
  before do
  end
  context "gcd 2" do
    it "gcd" do
      results = gcd(24,'jh')
      expect(results).to be_a(ArgumentError)
    end
  end
end

describe "演習4 a" do
  before do
  end
  context "a. 階乗の計算。" do
    it "fact #01" do
      results = fact(3)
      expect(results).to match(6)
    end
  end
end
describe "演習4 a" do
  before do
  end
  context "a. 階乗の計算。" do
    it "fact #02" do
      results = fact(4)
      expect(results).to match(24)
    end
  end
end
describe "演習4 a" do
  before do
  end
  context "a. 階乗の計算。" do
    it "fact #03" do
      results = fact('')
      expect(results).to be_a(RuntimeError)
    end
  end
end
describe "演習4 a" do
  before do
  end
  context "a. 階乗の計算。" do
    it "fact #04" do
      results = fact(nil)
      expect(results).to be_a(RuntimeError)
    end
  end
end
describe "演習4 a" do
  before do
  end
  context "a. 階乗の計算。" do
    it "fact #05" do
      results = fact(-1)
      expect(results).to be_a(RuntimeError)
    end
  end
end
describe "演習4 a" do
  before do
  end
  context "a. 階乗の計算。" do
    it "fact #06" do
      results = fact('AA')
      expect(results).to be_a(ArgumentError)
    end
  end
end
