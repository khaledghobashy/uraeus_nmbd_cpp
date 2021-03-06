#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 21:41:36 2019

@author: khaledghobashy
"""

# Third party imports
import sympy as sm
from sympy.printing.cxxcode import CXX11CodePrinter

class printer(CXX11CodePrinter):
    
    def _print_ZeroMatrix(self, expr):
        _expr = 'Eigen::MatrixXd::Zero(%s, %s)'%expr.shape
        return _expr
    
    def _print_zero_matrix(self, expr):
        _expr = 'Eigen::MatrixXd::Zero(%s, %s)'%expr.shape
        return _expr
        
    def _print_AbstractMatrix(self, expr):
        args = ', '.join([self._print(i) for i in expr.args])
        name = expr.__class__.__name__
        return '%s(%s)'%(name, args)
    
    def _print_Simple_geometry(self, expr):
        expr_lowerd = expr.__class__.__name__.lower()
        return '%s%s'%(expr_lowerd, (self._print(expr.args)))
    
    def _print_Cylinder_Geometry(self, expr):
        expr_lowerd = expr.__class__.__name__.lower()
        return '%s%s'%(expr_lowerd, (self._print(expr.args)))
    
    def _print_Triangular_Prism(self, expr):
        expr_lowerd = expr.__class__.__name__.lower()
        return '%s%s'%(expr_lowerd, (self._print(expr.args)))
    
    def _print_Triad(self, expr):
        args = ', '.join([self._print(i) for i in expr.args])
        name = expr.__class__.__name__.lower()
        return '%s(%s)'%(name, args)
    
    def _print_Skew(self, expr):
        args = ', '.join([self._print(i) for i in expr.args])
        name = expr.__class__.__name__.lower()
        return '%s(%s)'%(name, args)


    def _print_Equal_to(self, expr):
        return '%s'%self._print(expr.args[0])
    
    def _print_Oriented(self, expr):
        name = 'oriented'
        args = ', '.join([self._print(i) for i in expr.args])
        output = '%s({%s})'%(name, args)
        return output

    def _print_Mirrored(self, expr):
        name = 'mirrored'
        args = ', '.join([self._print(i) for i in expr.args])
        output = '%s({%s})'%(name, args)
        return output
    
    def _print_Centered(self, expr):
        name = 'centered'
        args = ', '.join([self._print(i) for i in expr.args])
        output = '%s({%s})'%(name, args)
        return output
    
    def _print_matrix_symbol(self, expr, declare=False, is_ref=False):
        name = expr._raw_name
        if declare:
            output = 'Eigen::Matrix<double, %s, %s> %s'%(*expr.shape, name)
        elif is_ref:
            output = 'Eigen::Ref<Eigen::Matrix<double, %s, %s>> %s'%(*expr.shape, name)
        else:
            output = '%s'%name
        return output
    
    def _print_dcm(self, expr, declare=False, is_ref=False):
        name = expr._raw_name
        if declare:
            output = 'Eigen::Matrix%sd %s'%(expr.shape[0], name)
        else:
            output = '%s'%name
        return output
    
    def _print_base_vector(self, expr, **kwargs):
        m = expr.frame.name
        index = expr.slice[0]
        return '%s.col(%s)'%(m, index)
    
    def _print_vector(self, expr, declare=False, hs='rhs', is_ref=False):
        name = expr._raw_name
        if hs == 'rhs':
            pass
        elif hs == 'lhs':
            declare = True
            
        if declare:
            output = 'Eigen::Vector3d %s'%name
        
        elif is_ref:
            output = 'Eigen::Ref<Eigen::Vector3d> %s'%name
        
        else:
            output = '%s'%name

        return output
    
    def _print_quatrenion(self, expr, declare=False, is_ref=False):
        name = expr._raw_name
        if declare:
            output = 'Eigen::Vector4d %s'%name
        elif is_ref:
            output = 'Eigen::Ref<Eigen::Vector4d> %s'%name
        else:
            output = '%s'%name
        
        return output
    
    def _print_MatrixSymbol(self, expr, declare=False, is_ref=False, **kwargs):
        if declare:
            if expr.shape == (3,1):
                output = 'Eigen::Vector3d %s'%(expr.name)
            elif expr.shape == (4,1):
                output = 'Eigen::Vector4d %s'%(expr.name)
            else:
                output = 'Eigen::Matrix<double, %s, %s> %s'%(*expr.shape, expr.name)        
        
        elif is_ref:
            if expr.shape == (3,1):
                output = 'Eigen::Ref<Eigen::Vector3d> %s'%(expr.name)
            elif expr.shape == (4,1):
                output = 'Eigen::Ref<Eigen::Vector4d> %s'%(expr.name)
            else:
                output = 'Eigen::Ref<Eigen::Matrix<double, %s, %s>> %s'%(*expr.shape, expr.name)
        
        else:
            output = super()._print_MatrixSymbol(expr, **kwargs)

        return output
    
    def _print_Geometry(self, expr, declare=False, **kwargs):
        if declare:
            output = 'auto %s'%expr.name
        else:
            output = super(CXX11CodePrinter, self)._print_Symbol(expr, **kwargs)
        return output

    
    def _print_Symbol(self, expr, declare=False, is_ref=False, **kwargs):
        if declare:
            output = 'double %s'%expr.name
        else:
            output = super(CXX11CodePrinter, self)._print_Symbol(expr, **kwargs)
        return output
    
    def _print_Mul(self,expr):
        text = ' * '.join([self._print(i) for i in expr.args])
        return '(%s)'%text

    def _print_Add(self,expr):
        text = ' + '.join([self._print(i) for i in expr.args])
        return '(%s)'%text
    
    def _print_MatAdd(self, expr):
        text = ' + '.join([self._print(i) for i in expr.args])
        return '(%s)'%text
    
    def _print_MatMul(self,expr):
        scalars = []
        vectors = []
        express = []
        args = expr.args
        
        for i in args:
            #print(i)
            if isinstance(i,sm.MatrixExpr) and not isinstance(i,sm.MatMul):
                #print('vector: %s'%i)
                #print(type(i))
                vectors.append(self._print(i))
            elif isinstance(i,sm.MatMul):
                #print('MatMul: %s'%i)
                vectors.append(self._print_MatMul(i))
            elif isinstance(i,sm.Number):
                #print('Scalar: %s'%i)
                scalars.append(self._print(i))
            else:
                #print('Expression: %s'%i)
                express.append(self._print(i))
        
        if len(scalars)==0:
            s = ''
        elif len(scalars) == 1:
            s = '%s * '%scalars[0]
        else:
            text = ' * '.join(scalars) + ' * '
            s = text
            
        if len(vectors)>1:
            text =  ' * '.join(vectors)
            v = text
        else:
            v = str(vectors[0])
            
        if len(express)==0:
            e = ''
        else:
            e = ' * '.join(express)+' * '
        #print('end \n')
        expr_text = '(%s)'%(s + e + v)
        return expr_text
        
    
    def _print_Identity(self, expr):
        _expr = 'Eigen::MatrixXd::Identity(%s, %s)'%expr.shape
        return _expr
    
    def _print_MatExpr(self, expr):
        return '%s'%expr._ccode()
    
    
    def _print_tuple(self, expr, declare=False, is_ref=False):
        if len(expr)>2:
            return super()._print_tuple(expr)
        else:
            lhs_name = self._print(expr[0], declare=declare)
            rhs_expr = self._print(expr[1])
            assign_operator = '='
            if (not declare) and (not is_ref) :
                try:
                    shape = expr[0].shape
                    if (shape[0] > 4):
                        assign_operator = '<<'
                except AttributeError:
                    pass
            _expr = '%s %s %s ;'%(lhs_name, assign_operator, rhs_expr)
            return _expr
    
    def _print_Equality(self, expr, declare=False, is_ref=False):
        lhs_name = self._print(expr.lhs, declare=declare, is_ref=is_ref)
        rhs_expr = self._print(expr.rhs)
        assign_operator = '='
        if not declare and not is_ref:
            try:
                expr.lhs.shape
                assign_operator = '<<'
            except AttributeError:
                pass
            
        _expr = '%s %s %s ;'%(lhs_name, assign_operator, rhs_expr)
        return _expr
        
    
    def _print_MatrixSlice(self, expr):
        m, row_slice, col_slice = expr.args
        if m.shape[1] == 1:
            start = row_slice[0]
            shape = expr.shape[0]
            value = '%s.segment(%s, %s)'%(self._print(m), start, shape)
        else:
            ij_start = '%s,%s'%(row_slice[0], col_slice[0])
            ij_shape = '%s,%s'%(expr.shape)
            value = '%s.block(%s, %s)'%(self._print(m), ij_start, ij_shape)
        return value
    
    def _print_MutableDenseMatrix(self, expr):
        _expr = ', '.join(['%s'%i for i in expr])
        return '%s'%(_expr)
    
    def _print_ImmutableDenseMatrix(self, expr):
        return self._print_MutableDenseMatrix(expr)
    
    def _print_UndefinedFunction(self, expr, declare=False):
        output_type = 'Eigen::Vector3d' if expr.is_Vector else 'double'
        if declare:
            text = 'std::function<%s(double)> %s'%(output_type, expr)
        else:
            text = '%s'%expr
        return text
    
    def _print_Function(self, expr):
        func = expr.__class__.__name__
        args = ','.join([self._print(arg) for arg in expr.args])
        return '%s(%s)'%(func, args)

    def _print_MatrixElement(self, expr):
        arg = expr.args[0]
        ind = expr.args[1:]
        if arg.shape == (1, 1):
            arg_text = self._print(arg)
        else:
            arg_text = super()._print_MatrixElement(expr)
        return arg_text
    
    def _print_MatPow(self, expr):
        arg, pow = expr.args
        if arg.shape == (1, 1):
            arg_text = self._print(arg)
            text = 'pow(%s, %s)'%(arg_text, pow)
        else:
            text = super()._print_MatPow(expr)
        return text
        
    def _print_transpose(self, expr):
        arg = expr.args[0]
        if isinstance(arg, sm.Symbol):
            text = self._print(arg)
        elif isinstance(arg, sm.MatrixSymbol) and arg.shape == (1, 1):
            text = self._print(arg)
        else:
            text = '%s.transpose()'%(*[self._print(i) for i in expr.args],)
        return text
    
    def _print_Transpose(self, expr):
        arg = expr.args[0]
        if isinstance(arg, sm.Symbol):
            text = self._print(arg)
        elif isinstance(arg, sm.MatrixSymbol) and arg.shape == (1, 1):
            text = self._print(arg)
        else:
            text = '%s.transpose()'%(*[self._print(i) for i in expr.args],)
        return text

    def _print_Derivative(self, expr):
        func = expr.args[0].__class__.__name__
        return 'derivative(%s, t, %s)'%(func, expr.args[1][1])
    
    def _print_Lambda(self, obj):
        args, expr = obj.args
        if len(args) == 1:
            return "lambda %s : %s" % (self._print(args.args[0]), self._print(expr))
        else:
            arg_string = ", ".join(self._print(arg) for arg in args)
            return "lambda (%s) : %s" % (arg_string, self._print(expr))


