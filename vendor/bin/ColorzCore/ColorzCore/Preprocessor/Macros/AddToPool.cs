﻿using System;
using System.Collections.Generic;
using ColorzCore.DataTypes;
using ColorzCore.Lexer;
using ColorzCore.Parser;

namespace ColorzCore.Preprocessor.Macros
{
    class AddToPool : BuiltInMacro
    {
        /*
         * Macro Usage:
         * AddToPool(tokens...): adds token to pool, and expands to label name referring to those tokens
         * AddToPool(tokens..., alignment): adds token to pool and make sure pooled tokens are aligned given alignment        
         */

        public Pool Pool { get; }

        public AddToPool(Pool pool)
        {
            Pool = pool;
        }

        public override IEnumerable<Token> ApplyMacro(Token head, IList<IList<Token>> parameters)
        {
            List<Token> line = new List<Token>(6 + parameters[0].Count);

            string labelName = Pool.MakePoolLabelName();

            if (parameters.Count == 2)
            {
                // Add Alignment directive 

                line.Add(new Token(TokenType.IDENTIFIER, head.Location, "ALIGN"));
                line.Add(parameters[1][0]);
                line.Add(new Token(TokenType.SEMICOLON, head.Location, ";"));
            }

            // TODO: Make label declaration global (when this feature gets implemented)
            // This way the name will be available as long as it is pooled (reguardless of pool scope)

            line.Add(new Token(TokenType.IDENTIFIER, head.Location, labelName));
            line.Add(new Token(TokenType.COLON, head.Location, ":"));

            line.AddRange(parameters[0]);
            line.Add(new Token(TokenType.NEWLINE, head.Location, "\n"));

            Pool.Lines.Add(new Pool.PooledLine(line));

            yield return new Token(TokenType.IDENTIFIER, head.Location, labelName);
        }

        public override bool ValidNumParams(int num)
        {
            return num == 1 || num == 2;
        }
    }
}
