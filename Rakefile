require 'yaml'

bin_dir = 'bin'

directory bin_dir

test_exe = File.join(bin_dir, 'hash-brown')
cpp_files = FileList['*.cpp']
file test_exe => cpp_files + [bin_dir] do
  sh %{clang++ --std=c++11 -o #{test_exe} #{cpp_files}}
end

strings = YAML.load_file("test_data.yml")

desc "test hash functions"
task :test => test_exe do
  sh %{#{test_exe.to_s} "#{strings.join '" "'}"}
end

task :default => test_exe
